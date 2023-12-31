#include "bad_alloc.hpp"
#include <unistd.h>
#include <iostream>
#include <errno.h>

ChunkInfo all_chunks{};

ChunkInfo* search_chunk(unsigned int size) {
    ChunkInfo* chunk = all_chunks.next;
    if(chunk == nullptr){
        return &all_chunks;
    }

    while(chunk->next != nullptr){
        chunk = chunk->next;
    }

    return chunk;
}

void* bad_malloc(unsigned int size) {
    ChunkInfo* chunk;
    
    unsigned int size_chunk{size * SIZE_CHUNK_IN_BITS};
    
    ChunkInfo* address = (ChunkInfo*) sbrk(size_chunk);

    chunk->next = address;
    chunk->chunk_size = size_chunk;
    
    ChunkInfo* last_chunk_available = search_chunk(size_chunk);
    chunk->prev = last_chunk_available;
    last_chunk_available->next = address;

    return chunk->address;
}

void bad_memory_free(void* chunk) {
    ChunkInfo* chunk_converted = (ChunkInfo*) chunk;
    if(chunk_converted->address == nullptr){
        std::cout << "ERROR: Your trying to set a non allocated address free.";
        return;
    }
    brk(chunk_converted->address);
    chunk_converted->address = nullptr;
    chunk_converted->next = nullptr;
    chunk_converted->prev->next = nullptr;
}