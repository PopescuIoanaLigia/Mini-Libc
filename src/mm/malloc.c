// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	if (size == 0) {
        return NULL;
    }
    size_t page_size = 4096;
    size_t aligned_size = (size + page_size - 1) & ~(page_size - 1);
    void *mem = mmap(NULL, aligned_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (mem == MAP_FAILED) {
        return NULL;
    }
    if (mem_list_add(mem, aligned_size) != 0) {
        munmap(mem, aligned_size);
        return NULL;
    }

    return mem;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	size_t total_size = nmemb * size;
    void *ptr = mmap(NULL, total_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (ptr == MAP_FAILED)
        return NULL;
    memset(ptr, 0, total_size);
    if (mem_list_add(ptr, total_size) == -1) {
        munmap(ptr, total_size);
        return NULL;
    }
    return ptr;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	if (ptr == NULL)
        return;
    struct mem_list *item = mem_list_find(ptr);
    if (item != NULL) {
        mem_list_del(ptr);
        munmap(ptr, item->len);
    }
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	
	return NULL;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	return NULL;
}
