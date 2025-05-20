//
// Created by GABRIEL on 20/05/2025.
//

#ifndef CONFIG_H
#define CONFIG_H

struct Config {
    int sim_duration;
    int nof_users;
    int nof_workers;
    int nof_worker_seats;
    int explode_threshold;
    int n_nano_secs;
    int p_serv_min;
    int p_serv_max;
};

extern struct Config cfg;

int load_config(const char *filename, struct Config* cfg);

#endif //CONFIG_H
