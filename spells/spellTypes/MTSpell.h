#ifndef MTSPELL_H
#define MTSPELL_H

#include <iostream>
#include "../Spell.h"
#include "../../units/SpellCaster.h"

template <class Type>
class SpellCaster;

template <class Type>
class MTSpell : public Spell<Type> {
    public:
        MTSpell(SpellEnum sEnum, SpellEnum sType, Type power, Type manaCost, const std::string& spellName);
        MTSpell(const Spell<Type>& prototype, SpellCaster<Type>& caster);
        virtual ~MTSpell();
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const MTSpell<Type>& spell);

#endif // MTSPELL_H
