#include "bad_alloc.hpp"
#include <iostream>

int main() {
    int* first_alloc = (int*) bad_malloc(2 * sizeof(int));
    first_alloc[0] = 333;
    first_alloc[1] = 444;

    std::cout << "First position: " << first_alloc[0] << '\n';
    std::cout << "Second position: " << first_alloc[1] << '\n';

    std::cout << "Address First alloc position: " << &first_alloc << '\n';

    bad_memory_free(first_alloc);
    std::cout << "EVERYTHING ok\n";
    return 0;
}