#ifndef DDSPELL_H
#define DDSPELL_H

#include <iostream>
#include "../Spell.h"
#include "../SpellEnum.cpp"

class DDSpell : public Spell {
    public:
        DDSpell(SpellEnum sEnum, int power, int manaCost, const std::string& spellName);
        virtual ~DDSpell();
};

std::ostream& operator<<(std::ostream& out, const DDSpell* spell);

#endif // DDSPELL_H
