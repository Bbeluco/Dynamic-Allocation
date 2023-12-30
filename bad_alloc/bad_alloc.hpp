#ifndef BAD_ALLOC_H
#define BAD_ALLOC_H

const unsigned int SIZE_CHUNK_IN_BITS{16}; //Default chunk size in 64-bits systems when use malloc

struct ChunkInfo {
    int* address{};
    int chunk_size{};
    struct ChunkInfo* next{nullptr};
    struct ChunkInfo* prev{nullptr};
};

void* bad_malloc(unsigned int size);

#endif