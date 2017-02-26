#ifndef DMTSPELL_H
#define DMTSPELL_H

#include <iostream>
#include "../Spell.h"

template <class Type>
class DMTSpell : public Spell<Type> {
    public:
        DMTSpell(SpellEnum sEnum, SpellEnum sType, Type power, Type manaCost, const std::string& spellName);
        virtual ~DMTSpell();
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const DMTSpell<Type>& spell);

#endif // DMTSPELL_H
