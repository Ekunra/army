#ifndef DDTSPELL_H
#define DDTSPELL_H

#include <iostream>
#include "../Spell.h"

template <class Type>
class DDTSpell : public Spell<Type> {
    public:
        DDTSpell(SpellEnum sEnum, SpellEnum sType, Type power, Type manaCost, const std::string& spellName);
        DDTSpell(const Spell<Type>& prototype);
        virtual ~DDTSpell();
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const DDTSpell<Type>& spell);

#endif // DDSPELL_H
