#include <iostream>
#include "states/limitedfield/LimitedField.h"
#include "states/damage/Damage.h"
#include "states/States.h"

int main() {
    Damage<double>* d1 = new Damage<double>(30);
    States<double>* s1 = new States<double>(100, 30, "Soldier");
    std::cout << "d1 - " << *d1 << std::endl;
    std::cout << "------------------------------" << std::endl;

    for ( int i = 20; i > 0; i-- ) {
        std::cout << d1->getDamage() << ' ';
    }
    std::cout << d1->getDamage() << std::endl;

    std::cout << "------------------------------" << std::endl;

    std::cout << "s1 HitPoints      " << s1->getHitPoints() << ';' << std::endl;
    std::cout << "s1 HitPointsLimit " << s1->getHitPointsLimit() << ';' << std::endl;
    std::cout << "s1 Max Damage :   " << s1->getMaxDmg() << ';' << std::endl;
    std::cout << "s1 Min Damage :   " << s1->getMinDmg() << ';' << std::endl;
    std::cout << "s1 Current Damage:" << s1->getDamage() << ';' << std::endl;

    if ( s1->getUEnum() == UnitEnum::DEFAULT ) {
        std::cout << "Super" << std::endl;
    } else {
        std::cout << "Fuck" << std::endl;
    }

    std::cout << "s1 Title      :   " << s1->getTitle() << ';' << std::endl;

    int a = 10;
    double b = 11.7;
    float c = 5.33333;

    std::cout << "------------------------------" << std::endl;


    delete d1;
    delete s1;
    return 0;
}
