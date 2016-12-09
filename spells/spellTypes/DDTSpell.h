#ifndef DDTSPELL_H
#define DDTSPELL_H

#include <iostream>
#include "../Spell.h"
#include "../SpellEnum.cpp"

class DDTSpell : public Spell {
    public:
        DDTSpell(SpellEnum sEnum, int power, int manaCost, const std::string& spellName);
        virtual ~DDTSpell();
};

std::ostream& operator<<(std::ostream& out, const DDTSpell* spell);

#endif // DDSPELL_H
