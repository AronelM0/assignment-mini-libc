// SPDX-License-Identifier: BSD-3-Clause

#include <internal/syscall.h>
#include <internal/arch/x86_64/syscall_list.h>
#include <time.h>
#include <errno.h>

int nanosleep(const struct timespec *req, struct timespec *rem)
{
    long ret = syscall(__NR_nanosleep, req, rem);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return 0;
}
