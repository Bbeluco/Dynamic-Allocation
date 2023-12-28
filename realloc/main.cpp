#include <iostream>
#include <stdlib.h>

/*
    This code proves that if we change the allocation of memory, 
    it can change the pointer that has been used to a new address too

    This explains why we have to reasign a value to our current pointer

    In my tests, I notice that if we make a small difference in length, theres a high chance
    to the original initial address remains the same and only allocates more memory in the heap


    NOTE: According to https://www.gnu.org/software/libc/manual/html_node/Changing-Block-Size.html
    Its highly recommended to use reallocarray() if the size of new memory is too big. 
    This occurs bc "reallocarray" fails safely if the system dont have more memory to execute the reallocation
*/

const int total_chunks{5};

void printAddress(int * p) {
    for (size_t i = 0; i < 2 * total_chunks; i++) {
        std::cout << "Address p" << i << ": " << &p[i]  << " | Value: " << p[i] << '\n';
    }
}

int main() {
    int* pointer_int{};
    pointer_int = (int*) malloc(total_chunks * sizeof(int*));
    std::cout << "Pre realloc\n";
    printAddress(pointer_int);
    
    pointer_int = (int *) realloc(pointer_int, 200 * total_chunks);

    std::cout << "\n\nPost realloc\n";
    printAddress(pointer_int);

    return 0;
}