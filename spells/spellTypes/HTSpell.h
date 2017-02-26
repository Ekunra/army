#ifndef HTSPELL_H
#define HTSPELL_H

#include <iostream>
#include "../Spell.h"

template <class Type>
class HTSpell : public Spell<Type> {
    public:
        HTSpell(SpellEnum sEnum, SpellEnum sType, Type power, Type manaCost, const std::string& spellName);
        virtual ~HTSpell();
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const HTSpell<Type>& spell);

#endif // HEALSPELL_H
