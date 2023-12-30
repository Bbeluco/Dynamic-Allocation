#include <unistd.h>
#include <iostream>

int main() {
    void * current_heap_break = sbrk(0);
    std::cout << current_heap_break << '\n';

    int* first_malloc = (int *) malloc(sizeof(int));

    current_heap_break = sbrk(0);
    std::cout << first_malloc << '\n';
    std::cout << current_heap_break << '\n';

    current_heap_break = sbrk(1);
    std::cout << current_heap_break << '\n';

    current_heap_break = sbrk(0);
    std::cout << current_heap_break << '\n';
    return 0;
}