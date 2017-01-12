#include <iostream>
#include "states/limitedfield/LimitedField.h"
#include "states/damage/Damage.h"
#include "states/States.h"
#include "units/Unit.h"
#include "units/soldier/Soldier.h"
#include "units/rogue/Rogue.h"

int main() {
    Soldier<float>* sr1 = new Soldier<float>("sr1");
    Rogue<float>* r1 = new Rogue<float>("R1");
    std::cout << *sr1 << std::endl;
    std::cout << *r1 << std::endl;
    std::cout << "------------------------------" << std::endl;
    sr1->attack(r1);
    std::cout << *sr1 << std::endl;
    std::cout << *r1 << std::endl;
    std::cout << "------------------------------" << std::endl;
    r1->attack(sr1);
    std::cout << *sr1 << std::endl;
    std::cout << *r1 << std::endl;
    std::cout << "------------------------------" << std::endl;

    double a = 5;
    double b = (double)a;


    std::cout << "------------------------------" << std::endl;

    delete sr1;
    return 0;
}
