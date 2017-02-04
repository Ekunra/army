#ifndef IMPLOSION_H
#define IMPLOSION_H

#include "../Spell.h"

template <class Type>
class Implosion : public Spell<Type> {
    protected:
    public:
        Implosion(SpellEnum sEnum=IMPLOSION, Type power=(Type)SPower::IMPLOSION, Type manaCost=(Type)SCost::IMPLOSION, const std::string& spellName="Implosion");
        virtual ~Implosion();
};

#endif // IMPLOSION_H
