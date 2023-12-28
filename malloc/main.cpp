#include <stdlib.h>
#include <iostream>
#include <string>

struct Person {
    std::string name{};
    int age{};
};

int main() {
    Person * pPerson{};
    pPerson = (Person*) malloc(sizeof(Person));

    if(pPerson == nullptr) {
        std::cout << "No memory available\n";
        return -1;
    }

    pPerson->name="Bruno";
    pPerson->age=21;

    std::cout << pPerson->name << '\n';
    std::cout << pPerson->age << '\n';
    return 0;
}