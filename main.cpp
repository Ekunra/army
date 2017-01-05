#include <iostream>
#include "states/limitedfield/LimitedField.h"
#include "states/damage/Damage.h"
#include "states/States.h"
#include "units/Unit.h"
#include "units/soldier/Soldier.h"

int main() {
    States<double>* s1 = new States<double>(100, 30, "Soldier");
    Soldier<double>* sr1 = new Soldier<double>("u1");
    std::cout << "------------------------------" << std::endl;



    std::cout << "------------------------------" << std::endl;


    delete s1;
    delete sr1;
    return 0;
}
