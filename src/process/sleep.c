// SPDX-License-Identifier: BSD-3-Clause

#include <internal/syscall.h>
#include <internal/arch/x86_64/syscall_list.h>
#include <time.h>
#include <errno.h>

unsigned int sleep(unsigned int seconds)
{
    struct timespec req, rem;
    long ret;

    req.tv_sec = seconds;
    req.tv_nsec = 0;

    ret = syscall(__NR_nanosleep, &req, &rem);

    if (ret < 0) {
        if (errno == EINTR) {
            return (unsigned int)rem.tv_sec + (rem.tv_nsec > 0 ? 1 : 0);
        }
        errno = -ret;
        return seconds;
     }

    return 0;
}
