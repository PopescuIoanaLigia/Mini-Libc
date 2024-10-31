#ifndef TIME_H
#define TIME_H

#include <internal/types.h>

struct timespec {
    uint64_t tv_sec;   /* Secunde */
    uint64_t tv_nsec;  /* Nanosecunde */
};

int nanosleep(const struct timespec *req, struct timespec *rem);

#endif
