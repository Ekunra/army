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
    // Rogue<double>* r1 = new Rogue<double>("RG1");
    Wizard<double>* w1 = new Wizard<double>("WZ1");
    Wizard<double>* w2 = new Wizard<double>("WZ2");

    std::cout << "------------------------------" << std::endl;

    std::cout << *sr1 << std::endl;
    // std::cout << *r1 << std::endl;
    std::cout << *w1 << std::endl;
    std::cout << *w2 << std::endl;

    std::cout << "------------------------------" << std::endl;

    w1->cast(FIREBALL, sr1);
    std::cout << "------------------------------" << std::endl;
    w1->cast(FIREBALL, w2);
    // w1->attack(w2);

    std::cout << "------------------------------" << std::endl;
    // std::cout << *w1 << std::endl;
    // std::cout << *w2 << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "------------------------------" << std::endl;

    delete sr1;
    // delete r1;
    delete w1;
    delete w2;
    return 0;
}
