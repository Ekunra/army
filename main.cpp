#include <iostream>
// #include "states/limitedfield/LimitedField.h"
// #include "states/damage/Damage.h"
// #include "states/States.h"
// #include "units/Unit.h"
#include "units/soldier/Soldier.h"
#include "units/rogue/Rogue.h"
#include "spells/SpellBook.h"
#include "spells/Spell.h"


int main() {
    Soldier<float>* sr1 = new Soldier<float>("sr1");
    Rogue<float>* r1 = new Rogue<float>("R1");
    std::cout << "------------------------------" << std::endl;
    std::cout << *sr1 << std::endl;
    std::cout << *r1 << std::endl;
    std::cout << "------------------------------" << std::endl;
    r1->bite(sr1);
    // sr1->attack(r1);
    // std::cout << *sr1 << std::endl;
    // std::cout << *r1 << std::endl;
    std::cout << "------------------------------" << std::endl;

    Spell<double>* s1 = new Spell<double>(FIREBALL, 100, 20, "Fireball");
    delete s1;
    std::cout << "------------------------------" << std::endl;

    SpellBook<double>* sb1 = new SpellBook<double>();
    sb1->insertSpell(FIREBALL, new Spell<double>(FIREBALL, 10, 20, "Fireball"));
    sb1->insertSpell(BLESS, new Spell<double>(BLESS, 10, 20, "Bless"));
    sb1->insertSpell(IMPLOSION, new Spell<double>(IMPLOSION, 10, 20, "Implosion"));
    delete sb1;

    std::cout << "------------------------------" << std::endl;

    delete sr1;
    delete r1;
    return 0;
}
