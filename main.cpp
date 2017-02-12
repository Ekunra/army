#include <iostream>
#include <memory>
// #include "states/limitedfield/LimitedField.h"
// #include "states/damage/Damage.h"
// #include "states/States.h"
// #include "units/Unit.h"
#include "units/soldier/Soldier.h"
#include "units/rogue/Rogue.h"
#include "units/wizard/Wizard.h"
#include "spells/SpellBook.h"
#include "spells/Spell.h"
#include "states/SpellCasterStates.h"


int main() {
    Soldier<double>* sr1 = new Soldier<double>("SR1");
    Rogue<double>* r1 = new Rogue<double>("RG1");
    Wizard<double>* w1 = new Wizard<double>("WZ1");

    std::cout << "------------------------------" << std::endl;

    std::cout << *sr1 << std::endl;
    std::cout << *r1 << std::endl;
    std::cout << *w1 << std::endl;

    std::cout << "------------------------------" << std::endl;

    r1->attack(w1);
    std::cout << "------------------------------" << std::endl;
    sr1->attack(r1);

    std::cout << "------------------------------" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "------------------------------" << std::endl;

    delete sr1;
    delete r1;
    delete w1;
    return 0;
}
