#include "bad_alloc.hpp"
#include <iostream>

int main() {
    
    bad_malloc((2 * sizeof(int)));
    bad_malloc((2 * sizeof(int)));
    int* first_alloc = (int*) bad_malloc(2 * sizeof(int));
    first_alloc[0] = 333;
    first_alloc[1] = 444;

    std::cout << "First position: " << first_alloc[0] << '\n';
    std::cout << "Second position: " << first_alloc[1] << '\n';
    return 0;
}