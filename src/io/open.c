// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <internal/arch/x86_64/syscall_list.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
    int mode = 0;
    long ret;

    if (flags & O_CREAT) {
        va_list args;
        va_start(args, flags);
        mode = va_arg(args, int);
        va_end(args);
    }

    ret = syscall(__NR_open, filename, flags, mode);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return (int)ret;
}
