// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <internal/arch/x86_64/syscall_list.h>
#include <errno.h>
#include <sys/types.h>

int ftruncate(int fd, off_t length)
{
    long ret = syscall(__NR_ftruncate, fd, length);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return (int)ret;
}
