#include <iostream>
#include "states/States.h"
#include "units/Unit.h"

int main() {
    States* state = new States(100, 20, "Wizard");
    std::cout << *state << std::endl;
    delete state;

    Unit* u1 = new Unit("u1", 100, 20 , "Berserker");
    std::cout << *u1 << std::endl;
    delete u1;

    return 0;
}
