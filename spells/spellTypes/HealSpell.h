#ifndef HEALSPELL_H
#define HEALSPELL_H

#include <iostream>
#include "../Spell.h"
#include "../SpellEnum.cpp"

class HealSpell : public Spell {
    public:
        HealSpell(SpellEnum sEnum, int power, int manaCost, const std::string& spellName);
        virtual ~HealSpell();
};

std::ostream& operator<<(std::ostream& out, const HealSpell* spell);

#endif // HEALSPELL_H
