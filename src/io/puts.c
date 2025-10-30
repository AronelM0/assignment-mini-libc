// SPDX-License-Identifier: BSD-3-Clause

#include <internal/syscall.h>
#include <internal/arch/x86_64/syscall_list.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int puts(const char *s)
{
    size_t len = strlen(s);
    long ret;

    ret = syscall(__NR_write, STDOUT_FILENO, s, len);
    if (ret < 0) {
        errno = -ret;
        return EOF;
    }

    ret = syscall(__NR_write, STDOUT_FILENO, "\n", 1);
    if (ret < 0) {
        errno = -ret;
        return EOF;
    }

    return (int)(len + 1);
}
