#include "bad_alloc.hpp"
#include <unistd.h>
#include <iostream>
#include <errno.h>

ChunkInfo all_chunks{};

ChunkInfo* get_last_chunk_available() {
    ChunkInfo* last_chunk = all_chunks.next;
    if(last_chunk == nullptr){
        return &all_chunks;
    }
    while(last_chunk->next != nullptr){
        last_chunk = last_chunk->next;
    }

    return last_chunk;
}

void* bad_malloc(unsigned int size) {
    ChunkInfo* chunk;
    
    unsigned int size_chunk{size * SIZE_CHUNK_IN_BITS};
    ChunkInfo* address = (ChunkInfo*) sbrk(size_chunk);
    chunk->next = address;
    chunk->chunk_size = size_chunk;
    
    ChunkInfo* last_chunk_available = get_last_chunk_available();
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
}