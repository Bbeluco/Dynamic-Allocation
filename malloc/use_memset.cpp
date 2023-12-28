#include <stdlib.h>
#include <string.h>
#include <iostream>

int main() {
    int *p;
    const int memory_blocks{5};
    p = (int*) malloc(memory_blocks * sizeof(p));

    //The line below do the same thing as call calloc to reset the internal memory information
    memset(p, 1, memory_blocks * sizeof(int));


    for (size_t i = 0; i < memory_blocks; i++) {
        std::cout << "Address of p" << i << " = " << &p[i] << " | value = "<< p[i] << '\n';
    }
    
    return 0;
}