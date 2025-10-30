// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <internal/arch/x86_64/syscall_list.h> // Include syscall numbers
#include <errno.h>

int fstat(int fd, struct stat *st)
{
    long ret = syscall(__NR_fstat, fd, st);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return (int)ret;
}
