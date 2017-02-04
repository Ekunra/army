#include <iostream>
// #include "states/limitedfield/LimitedField.h"
// #include "states/damage/Damage.h"
// #include "states/States.h"
// #include "units/Unit.h"
#include "units/soldier/Soldier.h"
#include "units/rogue/Rogue.h"
#include "units/wizard/Wizard.h"
#include "spells/SpellBook.h"
#include "spells/Spell.h"


int main() {
    // Soldier<double>* sr1 = new Soldier<double>("sr1");
    Wizard<double>* w1 = new Wizard<double>("W1");
    // Spell<double>* fireball = new Spell<double>(FIREBALL, 20.0, 15.0, "FireBall");
    std::cout << "------------------------------" << std::endl;
    // std::cout << *sr1 << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "------------------------------" << std::endl;

    // Spell<double>* s1 = new Spell<double>(FIREBALL, 100, 20, "Fireball");
    // delete s1;
    // std::cout << "------------------------------" << std::endl;

    // SpellBook<double>* sb1 = new SpellBook<double>();
    // sb1->insertSpell(FIREBALL, new Spell<double>(FIREBALL, 10, 20, "Fireball"));
    // sb1->insertSpell(BLESS, new Spell<double>(BLESS, 10, 20, "Bless"));
    // sb1->insertSpell(IMPLOSION, new Spell<double>(IMPLOSION, 10, 20, "Implosion"));
    // delete sb1;

    std::cout << "------------------------------" << std::endl;
    std::cout << "------------------------------" << std::endl;

    // delete sr1;
    delete w1;
    // delete fireball;
    return 0;
}
