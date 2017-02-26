#ifndef ACTSPELL_H
#define ACTSPELL_H

#include <iostream>
#include "../Spell.h"

template <class Type>
class ACTSpell : public Spell<Type> {
    public:
        ACTSpell(SpellEnum sEnum, SpellEnum sType, Type power, Type manaCost, const std::string& spellName);
        virtual ~ACTSpell();
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const ACTSpell<Type>& spell);

#endif // ACTSPELL_H
