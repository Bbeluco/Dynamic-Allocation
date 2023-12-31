#ifndef BAD_ALLOC_H
#define BAD_ALLOC_H

const unsigned int SIZE_CHUNK_IN_BITS{16}; //Default chunk size in 64-bits systems when use malloc

struct ChunkInfo {
    int* address{nullptr};
    int chunk_size{0};
    struct ChunkInfo* next{nullptr};
    struct ChunkInfo* prev{nullptr};
};

void* bad_malloc(unsigned int size);
void bad_memory_free(void* chunk);

#endif