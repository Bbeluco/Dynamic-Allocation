#include <stdlib.h>
#include <string>
#include <iostream>

/*
    The sintax of calloc is a little bit different from malloc/realloc

    The first argument we must pass how many chunks do we want to reservate
    The second argument we need to inform how long are these chunks
*/

struct Person {
    std::string name{};
    int age{};
};

int main() {
    Person* pPerson{};
    int total_chunks{2};
    pPerson = (Person*) calloc(total_chunks, sizeof(Person));

    for(size_t i = 0; i < total_chunks; ++i){
        std::cout << "pPerson[" << i << "]: " << (pPerson+i)->age << '\n';
    }
    
    return 0;
}