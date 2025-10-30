// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <internal/arch/x86_64/syscall_list.h>
#include <fcntl.h> // <-- SCHIMBĂ LINIA ASTA
#include <errno.h>

// Am șters (void)path și (void)buf - nu mai sunt necesare
int stat(const char *restrict path, struct stat *restrict buf)
{
    long ret = syscall(__NR_newfstatat, AT_FDCWD, path, buf, 0);

    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return (int)ret;
}
