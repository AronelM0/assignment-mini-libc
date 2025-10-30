// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <internal/arch/x86_64/syscall_list.h>
#include <errno.h>

int close(int fd)
{
    long ret = syscall(__NR_close, fd);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return (int)ret;
}
