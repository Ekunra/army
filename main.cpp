#include <iostream>
#include "states/limitedfield/LimitedField.h"
#include "states/damage/Damage.h"
#include "states/States.h"
#include "units/Unit.h"
#include "units/soldier/Soldier.h"

int main() {
    Soldier<double>* sr1 = new Soldier<double>("sr1");
    Soldier<double>* sr2 = new Soldier<double>("sr2");
    std::cout << *sr1 << std::endl;
    std::cout << *sr2 << std::endl;
    std::cout << "------------------------------" << std::endl;
    sr1->attack(sr2);
    std::cout << *sr1 << std::endl;
    std::cout << *sr2 << std::endl;
    std::cout << "------------------------------" << std::endl;
    sr1->attack(sr2);
    std::cout << *sr1 << std::endl;
    std::cout << *sr2 << std::endl;

    std::cout << "------------------------------" << std::endl;

    delete sr1;
    return 0;
}
