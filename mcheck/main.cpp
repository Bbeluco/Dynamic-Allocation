#include <mcheck.h>
#include <stdio.h>
#include <iostream>


int main() {
    char *p;

    std::cout << "Check if everything ok in the heap\n";
    if(mcheck(NULL) != 0) {
        std::cout << "Error in the HEAP detected\n";
        return -1;
    }

    p = (char*)malloc(sizeof(char));
    std::cout << "First FREE\n";
    free(p);

    std::cout << "Second FREE\n";
    free(p);
    return 0;
}