#include <iostream>
#include "states/limitedfield/LimitedField.h"
#include "states/damage/Damage.h"
#include "states/States.h"
#include "units/Unit.h"
#include "units/soldier/Soldier.h"

int main() {
    Soldier<double>* sr1 = new Soldier<double>("u1");
    std::cout << "------------------------------" << std::endl;

    std::cout << *sr1 << std::endl;

    std::cout << "------------------------------" << std::endl;

    delete sr1;
    return 0;
}
