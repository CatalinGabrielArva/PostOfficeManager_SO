//
// Created by GABRIEL on 20/05/2025.
//

#include "../include/config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Config cfg;

int load_config(const char *filename, struct Config* cfg){

    FILE* f = fopen(filename, "r");
    if(f == NULL) return -1;

    char key[64];
    int value;

    while(fscanf(f, "%s %d", key, &value) == 2){
        if(strcmp(key, "SIM_DURATION") == 0) cfg->sim_duration = value;
        else if (strcmp(key, "NOF_USERS") == 0) cfg->nof_users = value;
        else if (strcmp(key, "NOF_WORKERS") == 0) cfg->nof_workers = value;
        else if (strcmp(key, "NOF_WORKER_SEATS") == 0) cfg->nof_worker_seats = value;
        else if (strcmp(key, "EXPLODE_THRESHOLD") == 0) cfg->explode_threshold = value;
        else if (strcmp(key, "N_NANO_SECS") == 0) cfg->n_nano_secs = value;
        else if (strcmp(key, "P_SERV_MIN") == 0) cfg->p_serv_min = value;
        else if (strcmp(key, "P_SERV_MAX") == 0) cfg->p_serv_max = value;
    }

    fclose(f);
    return 0;

}