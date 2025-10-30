// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

void *malloc(size_t size)
{
    if (size == 0) {
        return NULL;
    }

    size_t total_size = size + sizeof(size_t);

    void *block = mmap(NULL, total_size,
                       PROT_READ | PROT_WRITE,
                       MAP_PRIVATE | MAP_ANONYMOUS,
                       -1, 0);

    if (block == MAP_FAILED) {
        return NULL;
    }

    *(size_t *)block = total_size;

    return (void *)((char *)block + sizeof(size_t));
}

void *calloc(size_t nmemb, size_t size)
{
    size_t total_size = nmemb * size;

    if (size != 0 && total_size / size != nmemb) {
        return NULL;
    }

    return malloc(total_size);
}

void free(void *ptr)
{
    if (ptr == NULL) {
        return;
    }

    void *block_start = (void *)((char *)ptr - sizeof(size_t));
    size_t total_size = *(size_t *)block_start;

    munmap(block_start, total_size);
}

void *realloc(void *ptr, size_t size)
{
    if (ptr == NULL) {
        return malloc(size);
    }

    if (size == 0) {
        free(ptr);
        return NULL;
    }

    void *block_start = (void *)((char *)ptr - sizeof(size_t));
    size_t old_total_size = *(size_t *)block_start;
    size_t old_data_size = old_total_size - sizeof(size_t);

    void *new_ptr = malloc(size);
    if (new_ptr == NULL) {
        return NULL;
    }

    size_t copy_size;
    if (old_data_size < size) {
        copy_size = old_data_size;
    } else {
        copy_size = size;
    }

    memcpy(new_ptr, ptr, copy_size);
    free(ptr);

    return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    size_t total_size = nmemb * size;

    if (size != 0 && total_size / size != nmemb) {
        errno = ENOMEM;
        return NULL;
    }

    return realloc(ptr, total_size);
}
