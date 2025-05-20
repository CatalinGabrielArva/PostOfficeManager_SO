//
// Created by GABRIEL on 20/05/2025.
//

#include "../include/common.h"
#include <stdio.h>
#include <stdarg.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>

static int print_sem_id = -1;

void init_print_semaphore(){

    print_sem_id = semget(PRINT_SEM_KEY, 1, IPC_CREAT | 0666);
    if (print_sem_id == -1){
        perror("semget failed");
        exit(EXIT_FAILURE);
    }

    union semun {
        int val;
    } sem_val;

    sem_val.val = 1;
    if(semctl(print_sem_id, 0, SETVAL, sem_val) == -1){
        perror("semctl failed");
        exit(EXIT_FAILURE);
    }
}

void remove_print_semaphore(){
    if(print_sem_id == -1){
        print_sem_id = semget(PRINT_SEM_KEY, 1, 0666);
    }
    if(print_sem_id != 1){
        if(semctl(print_sem_id, 0, IPC_RMID) == -1){
            perror("semctl failed");
        }
    }
}

void safe_printf(const char *format, ...) {

    if(print_sem_id == -1){
        print_sem_id = semget(PRINT_SEM_KEY, 1, 0666);
        if(print_sem_id == -1){
            perror("semget failed");
            return;
        }
    }

    struct sembuf lock = {0, -1, 0};
    struct sembuf unlock = {0, 1, 0};

    semop(print_sem_id, &lock, 1);

    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    fflush(stdout);

    semop(print_sem_id, &unlock, 1);

}