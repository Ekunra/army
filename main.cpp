#include <iostream>
#include <memory>
// #include "states/limitedfield/LimitedField.h"
// #include "states/damage/Damage.h"
// #include "states/States.h"
// #include "units/Unit.h"
#include "Properties.h"
#include "units/soldier/Soldier.h"
#include "units/rogue/Rogue.h"
#include "units/wizard/Wizard.h"
#include "spells/SpellBook.h"
#include "spells/Spell.h"
#include "states/SpellCasterStates.h"


int main() {

    // MTSpell<double>* newSpell = new MTSpell<double>(MANAPORTION, MT_MAGIC, (double)sPower::MANAPORTION, (double)sCost::MANAPORTION, "ManaPortion");
    Soldier<int>* sr1 = new Soldier<int>("SR1");
    Rogue<int>* r1 = new Rogue<int>("RG1");
    Wizard<int>* w1 = new Wizard<int>("WZ1");
    Wizard<int>* w2 = new Wizard<int>("WZ2");

    std::cout << "------------------------------" << std::endl;

    std::cout << *sr1 << std::endl;
    std::cout << *r1 << std::endl;
    std::cout << *w1 << std::endl;
    std::cout << *w2 << std::endl;

    std::cout << "------------------------------" << std::endl;
    sr1->attack(r1);
    sr1->attack(r1);
    sr1->attack(r1);
    sr1->attack(r1);
    sr1->attack(r1);
    sr1->attack(r1);
    std::cout << *r1 << std::endl;
    std::cout << *sr1 << std::endl;
    std::cout << "------------------------------" << std::endl;

    w1->cast(FIREBALL, sr1);
    std::cout << *sr1 << std::endl;
    std::cout << *w1 << std::endl;
    
    std::cout << "------------------------------" << std::endl;

    w1->cast(HEAL, sr1);
    std::cout << *sr1 << std::endl;
    std::cout << *w1 << std::endl;

    std::cout << "------------------------------" << std::endl;

    w1->cast(MANAPORTION, sr1);
    std::cout << *sr1 << std::endl;
    std::cout << *w1 << std::endl;

    std::cout << "------------------------------" << std::endl;

    w1->cast(MANADRAIN, sr1);
    std::cout << *sr1 << std::endl;
    std::cout << *w1 << std::endl;

    std::cout << "------------------------------" << std::endl;
    // try {
        // w1->cast(MANADRAIN, w2);
    // } catch (ArmyException e) {
        // e.show();
    // }
    // std::cout << *w1 << std::endl;
    // std::cout << *w2 << std::endl;

    std::cout << "------------------------------" << std::endl;
    std::cout << *sr1 << std::endl;
    std::cout << *r1 << std::endl;
    std::cout << *w1 << std::endl;
    std::cout << *w2 << std::endl;
    std::cout << "------------------------------" << std::endl;
    // Spell<double> f1(FIREBALL, DDT_MAGIC, (double)SPower::FIREBALL, (double)SCost::FIREBALL, "FireBall");
    // Spell<double> f2(FIREBALL, DDT_MAGIC, 1000, 1000, "SampleBall");
    std::cout << "------------------------------" << std::endl;
    // std::cout << f1 << std::endl;
    // std::cout << f2 << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "------------------------------" << std::endl;
    // f1 = f2;
    std::cout << "------------------------------" << std::endl;
    // std::cout << f1 << std::endl;
    // std::cout << f2 << std::endl;
    std::cout << "------------------------------" << std::endl;

    // delete sr1;
    delete sr1;
    delete r1;
    delete w1;
    delete w2;
    return 0;
}
