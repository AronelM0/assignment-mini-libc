#ifndef _TIME_H_
#define _TIME_H_

#include <stddef.h>

struct timespec {
    long tv_sec;
    long tv_nsec;
};

unsigned int sleep(unsigned int seconds);
int nanosleep(const struct timespec *req, struct timespec *rem);

#endif /* _TIME_H_ */
