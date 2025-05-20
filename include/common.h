//
// Created by GABRIEL on 20/05/2025.
//

#ifndef COMMON_H
#define COMMON_H

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define PRINT_SEM_KEY 0x1234

void safe_printf(const char *format, ...);
void init_print_semaphore();
void remove_print_semaphore();

#endif //COMMON_H
