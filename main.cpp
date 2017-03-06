#include <iostream>
#include <memory>
#include "Properties.h"
#include "units/soldier/Soldier.h"
#include "units/rogue/Rogue.h"
#include "units/vampire/Vampire.h"
#include "units/wizard/Wizard.h"
#include "spells/SpellBook.h"
#include "spells/Spell.h"
#include "states/SpellCasterStates.h"


int main() {

    // MTSpell<double>* newSpell = new MTSpell<double>(MANAPORTION, MT_MAGIC, (double)sPower::MANAPORTION, (double)sCost::MANAPORTION, "ManaPortion");
    // Soldier<int>* sr1 = new Soldier<int>("SR1");
    // Rogue<int>* r1 = new Rogue<int>("RG1");
    // Wizard<int>* w1 = new Wizard<int>("WZ1");
    // Wizard<int>* w2 = new Wizard<int>("WZ2");
    Vampire<double>* v1 = new Vampire<double>("VR1");

    std::cout << "------------------------------" << std::endl;

    // std::cout << *sr1 << std::endl;
    // std::cout << *r1 << std::endl;
    std::cout << *v1 << std::endl;
    // std::cout << *w1 << std::endl;
    // std::cout << *w2 << std::endl;

    // std::cout << "------------------------------" << std::endl;
    // sr1->attack(r1);
    // sr1->attack(r1);
    // sr1->attack(r1);
    // sr1->attack(r1);
    // sr1->attack(r1);
    // sr1->attack(r1);
    // std::cout << *r1 << std::endl;
    // std::cout << *sr1 << std::endl;
    // std::cout << "------------------------------" << std::endl;
    // std::cout << "------------------------------" << std::endl;
    // std::cout << "------------------------------" << std::endl;
    // std::cout << "------------------------------" << std::endl;
    // std::cout << "------------------------------" << std::endl;

    // try {
        // w1->cast(MANADRAIN, w2);
    // } catch (ArmyException e) {
        // e.show();
    // }
    // std::cout << *w1 << std::endl;
    // std::cout << *w2 << std::endl;

    std::cout << "------------------------------" << std::endl;
    // std::cout << *sr1 << std::endl;
    // std::cout << *r1 << std::endl;
    // std::cout << *w1 << std::endl;
    // std::cout << *w2 << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "------------------------------" << std::endl;
    // LimitedField<double>* lf = new LimitedField<double>(100, FieldType::HEALTH);
    // Damage<double>* dam = new Damage<double>(3.33);
    // Defence* def = new Defence(1.5, 0.5);
    // States<double>* s = new States<double>(lf, dam, def, "WereWolf", UnitEnum::WOLF, UnitEnum::WOLF);
    std::cout << "------------------------------" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "------------------------------" << std::endl;

    // delete sr1;
    // delete sr1;
    // delete r1;
    delete v1;
    // delete w1;
    // delete w2;
    return 0;
}
