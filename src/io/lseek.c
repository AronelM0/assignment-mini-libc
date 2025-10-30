// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <internal/arch/x86_64/syscall_list.h>
#include <errno.h>
#include <sys/types.h>

off_t lseek(int fd, off_t offset, int whence)
{
    long ret = syscall(__NR_lseek, fd, offset, whence);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return (off_t)ret;
}
