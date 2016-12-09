#ifndef HTSPELL_H
#define HTSPELL_H

#include <iostream>
#include "../Spell.h"
#include "../SpellEnum.cpp"

class HTSpell : public Spell {
    public:
        HTSpell(SpellEnum sEnum, int power, int manaCost, const std::string& spellName);
        virtual ~HTSpell();
};

std::ostream& operator<<(std::ostream& out, const HTSpell* spell);

#endif // HEALSPELL_H
