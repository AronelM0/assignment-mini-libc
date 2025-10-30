// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>
#include <internal/arch/x86_64/syscall_list.h> // Header-ul care conține numerele

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
    // Am schimbat SYS_mmap în __NR_mmap
    long ret = syscall(__NR_mmap, addr, length, prot, flags, fd, offset);

    if (ret < 0 && ret > -4096) {
        errno = -ret;
        return MAP_FAILED;
    }

    return (void *)ret;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
    // Am schimbat SYS_mremap în __NR_mremap
    long ret = syscall(__NR_mremap, old_address, old_size, new_size, flags, 0);

    if (ret < 0 && ret > -4096) {
        errno = -ret;
        return MAP_FAILED;
    }

    return (void *)ret;
}

int munmap(void *addr, size_t length)
{
    // Am schimbat SYS_munmap în __NR_munmap
    long ret = syscall(__NR_munmap, addr, length);

    if (ret < 0 && ret > -4096) {
        errno = -ret;
        return -1;
    }

    return (int)ret;
}
