//
// Created by GABRIEL on 20/05/2025.
//

#ifndef WORKER_SEAT_H
#define WORKER_SEAT_H

#include <sys/types.h>

#define WORKER_SEAT_SHM_KEY 0x3456
#define WORKER_SEAT_SEM_KEY 0x5678

typedef struct {
    int id;
    int service_active;
    pid_t po_worker_pid;
    int is_available;
} WorkerSeat;

int worker_seats_create(int num_seats);
void worker_seats_init(int num_seats);
WorkerSeat *worker_seats_attach();
void worker_seats_detach(WorkerSeat *worker_seats);
void worker_seats_remove_ipc();

void worker_seat_lock(int index);
void worker_seat_unlock(int index);

#endif //WORKER_SEAT_H
