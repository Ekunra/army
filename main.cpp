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
    // Soldier<double>* sr1 = new Soldier<double>("SR1");

    // MTSpell<double>* newSpell = new MTSpell<double>(MANAPORTION, MT_MAGIC, (double)sPower::MANAPORTION, (double)sCost::MANAPORTION, "ManaPortion");
    Rogue<double>* r1 = new Rogue<double>("RG1");
    Wizard<double>* w1 = new Wizard<double>("WZ1");
    Wizard<double>* w2 = new Wizard<double>("WZ2");

    std::cout << "------------------------------" << std::endl;

    // std::cout << *sr1 << std::endl;
    std::cout << *r1 << std::endl;
    std::cout << *w1 << std::endl;
    std::cout << *w2 << std::endl;

    std::cout << "------------------------------" << std::endl;

    w1->cast(MANAPORTION, r1);
    std::cout << *r1 << std::endl;
    std::cout << *w1 << std::endl;

    std::cout << "------------------------------" << std::endl;
    
    w1->cast(FIREBALL, r1);
    std::cout << *r1 << std::endl;
    std::cout << *w1 << std::endl;

    std::cout << "------------------------------" << std::endl;
    
    w1->cast(FIREBALL, w2);
    std::cout << *w1 << std::endl;
    std::cout << *w2 << std::endl;
    
    std::cout << "------------------------------" << std::endl;
    
    w2->cast(MANAPORTION, w1);
    std::cout << *w1 << std::endl;
    std::cout << *w2 << std::endl;

    std::cout << "------------------------------" << std::endl;
    // try {
        w1->cast(MANADRAIN, w2);
    // } catch (ArmyException e) {
        // e.show();
    // }
    std::cout << *w1 << std::endl;
    std::cout << *w2 << std::endl;

    std::cout << "------------------------------" << std::endl;
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
    delete r1;
    delete w1;
    delete w2;
    return 0;
}
