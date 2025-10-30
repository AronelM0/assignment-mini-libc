#include <unistd.h>
#include <time.h>

unsigned int sleep(unsigned int seconds)
{
    struct timespec req, rem;
    req.tv_sec = seconds;
    req.tv_nsec = 0;
    if (nanosleep(&req, &rem) == 0)
        return 0;
    return rem.tv_sec;
}
