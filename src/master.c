//
// Created by GABRIEL on 20/05/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <fcntl.h>

#include "../include/config.h"
#include "../include/common.h"

int main() {

   init_print_semaphore();

   // Simulation started
   safe_printf("MASTER | Starting simulation...\n");

   remove_print_semaphore();

   return 0;


}