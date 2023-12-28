#include <stdlib.h>
#include <string>
#include <iostream>

struct Person {
    std::string name{};
    int age{};
};

/*
    This POC validates what doc (https://www.gnu.org/software/libc/manual/html_node/Freeing-after-Malloc.html) says about not clear the memory when we free the chunk
    Its not necessarily always and not all members, but in my tests, even if we have not
    defined the values for members in pPerson2 it takes the old address and the values
*/

int main() {
    Person * pPerson{};
    pPerson = (Person*) malloc(sizeof(Person));

    std::cout << "pPerson: " << pPerson << '\n';
    pPerson->name = "Bruno";
    pPerson->age = 21;

    free(pPerson);
    std::cout << "First pPerson free\n";

    Person * pPerson2{};
    pPerson2 = (Person*) malloc(sizeof(Person));
    std::cout << "pPerson2: " << pPerson2 << '\n';

    std::cout << "Name: " << pPerson2->name << '\n';
    std::cout << "Age: " << pPerson2->age << '\n';
    return 0;
}