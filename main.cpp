#include <iostream>
#include "states/limitedfield/LimitedField.h"
#include "states/damage/Damage.h"
#include "states/States.h"

int main() {
    Damage<double>* d1 = new Damage<double>(30);
    States<double>* s1 = new States<double>(100, 30, "Soldier");
    std::cout << "d1 - " << *d1 << std::endl;
    std::cout << "------------------------------" << std::endl;



    std::cout << "------------------------------" << std::endl;


    delete d1;
    delete s1;
    return 0;
}
