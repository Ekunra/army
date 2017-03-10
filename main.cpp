#include <iostream>
#include <memory>
#include "Properties.h"
#include "units/soldier/Soldier.h"
#include "units/rogue/Rogue.h"
#include "units/vampire/Vampire.h"
#include "units/werewolf/Werewolf.h"
#include "units/wizard/Wizard.h"
#include "spells/SpellBook.h"
#include "spells/Spell.h"
#include "states/SpellCasterStates.h"


int main() {

    // MTSpell<double>* newSpell = new MTSpell<double>(MANAPORTION, MT_MAGIC, (double)sPower::MANAPORTION, (double)sCost::MANAPORTION, "ManaPortion");
    // Soldier<double>* sr1 = new Soldier<double>("SR1");
    Rogue<double>* r1 = new Rogue<double>("RG1");
    Vampire<double>* v1 = new Vampire<double>("VR1");
    Werewolf<double>* ww1 = new Werewolf<double>("WW1");
    Wizard<double>* w1 = new Wizard<double>("WZ1");
    // Wizard<double>* w2 = new Wizard<double>("WZ2");

    std::cout << "------------------------------" << std::endl;

    // std::cout << *sr1 << std::endl;
    std::cout << *r1 << std::endl;
    // std::cout << *v1 << std::endl;
    std::cout << *ww1 << std::endl;
    // std::cout << *w1 << std::endl;
    // std::cout << *w2 << std::endl;

    std::cout << "------------------------------" << std::endl;
    ww1->useSecondaryAbility();
    std::cout << "------------------------------" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "------------------------------" << std::endl;
    // std::cout << "------------------------------" << std::endl;
    // std::cout << "------------------------------" << std::endl;
    // std::cout << "------------------------------" << std::endl;
    // std::cout << "------------------------------" << std::endl;

    // try {
        // w1->cast(MANADRAIN, w2);
    // } catch (ArmyException e) {
        // e.show();
    // }

    std::cout << "------------------------------" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "------------------------------" << std::endl;
    // std::cout << *sr1 << std::endl;
    std::cout << *r1 << std::endl;
    // std::cout << *v1 << std::endl;
    std::cout << *ww1 << std::endl;
    std::cout << *w1 << std::endl;
    // std::cout << *w2 << std::endl;
    std::cout << "------------------------------" << std::endl;

    // delete sr1;
    delete r1;
    delete v1;
    delete ww1;
    delete w1;
    // delete w2;
    return 0;
}
