#include <iostream>
#include <memory>
#include "observe/Observable.h"
#include "Properties.h"
#include "units/soldier/Soldier.h"
#include "units/berserker/Berserker.h"
#include "units/rogue/Rogue.h"
#include "units/vampire/Vampire.h"
#include "units/werewolf/Werewolf.h"
#include "units/wizard/Wizard.h"
#include "units/healer/Healer.h"
#include "units/priest/Priest.h"
#include "units/necromancer/Necromancer.h"
#include "spells/SpellBook.h"
#include "spells/Spell.h"
#include "states/SpellCasterStates.h"


int main() {
    Soldier<double>* sr1 = new Soldier<double>("SR1");
    Necromancer<double>* necr1 = new Necromancer<double>("NECR");
    // Berserker<double>* br1 = new Berserker<double>("BR1");
    // Rogue<double>* r1 = new Rogue<double>("RG1");
    // Vampire<double>* v1 = new Vampire<double>("VR1");
    // Werewolf<double>* ww1 = new Werewolf<double>("WW1");
    // Wizard<double>* w1 = new Wizard<double>("WZ1");
    // Healer<double>* h1 = new Healer<double>("HL1");
    // Priest<double>* p1 = new Priest<double>("PR1");

    std::cout << "------------------------------" << std::endl;

    // std::cout << *sr1 << std::endl;
    // std::cout << *br1 << std::endl;
    // std::cout << *r1 << std::endl;
    // std::cout << *v1 << std::endl;
    // std::cout << *ww1 << std::endl;
    // std::cout << *w1 << std::endl;
    // std::cout << *h1 << std::endl;
    // std::cout << *p1 << std::endl;

    std::cout << "------------------------------" << std::endl;
    // std::cout << *sr1 << std::endl;
    // w1->cast(FIREBALL, sr1);
    // std::cout << *sr1 << std::endl;
    // p1->cast(FIREBALL, sr1);
    // std::cout << *sr1 << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << "------------------------------" << std::endl;
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
    std::cout << *sr1 << std::endl;
    // std::cout << *br1 << std::endl;
    // std::cout << *r1 << std::endl;
    // std::cout << *v1 << std::endl;
    // std::cout << *ww1 << std::endl;
    // std::cout << *w1 << std::endl;
    // std::cout << *h1 << std::endl;
    // std::cout << *p1 << std::endl;
    // std::cout << *w2 << std::endl;
    std::cout << *necr1 << std::endl;
    std::cout << "------------------------------" << std::endl;

    delete sr1;
    // delete br1;
    // delete r1;
    // delete v1;
    // delete ww1;
    // delete w1;
    // delete h1;
    // delete p1;
    // delete w2;
    delete necr1;
    return 0;
}
