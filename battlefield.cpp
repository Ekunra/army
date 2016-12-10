#include <iostream>
#include "states/States.h"
#include "units/Unit.h"
#include "units/soldier/Soldier.h"
#include "units/rogue/Rogue.h"
#include "spells/SpellBook.h"
#include "spells/Spell.h"
#include "spells/spellTypes/DDTSpell.h"
#include "spells/spellTypes/HTSpell.h"

int main() {
    Rogue* r1 = new Rogue("r1");
    std::cout << *r1 << std::endl;

    Soldier* s2 = new Soldier("s2");
    std::cout << *s2 << std::endl;

    s2->attack(r1);
    std::cout << "* --- Next round --- " << std::endl;
    s2->attack(r1);
    std::cout << "* --- Next round --- " << std::endl;
    s2->attack(r1);
    std::cout << "* --- Next round --- " << std::endl;
    r1->attack(s2);
    std::cout << "* --- Next round --- " << std::endl;
    r1->attack(s2);

    std::cout << *r1 << std::endl;
    std::cout << *s2 << std::endl;

    delete r1;
    delete s2;

    std::cout << "------------------" << std::endl;

    DDTSpell* spell = new DDTSpell(FIREBALL, 20, 20, "FireBall");
    std::cout << spell << std::endl;
    HTSpell* heal = new HTSpell(BLESS,50,30,"Bless");
    std::cout << heal << std::endl;

    delete spell;
    delete heal;

    std::cout << "------------------" << std::endl;

    FireBall* fireBall = new FireBall;
    delete fireBall;

    std::cout << "------------------" << std::endl;

    SpellBook* spellBook = new SpellBook;
    delete spellBook;

    return 0;
}
