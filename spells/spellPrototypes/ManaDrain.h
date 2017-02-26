#ifndef MANADRAIN_H
#define MANADRAIN_H

#include "../Spell.h"

template <class Type>
class ManaDrain : public Spell<Type> {
    protected:
    public:
        ManaDrain(SpellEnum sEnum=MANADRAIN, SpellEnum sType=DMT_MAGIC, Type power=(Type)SPower::MANADRAIN, Type manaCost=(Type)SCost::MANADRAIN, const std::string& spellName="ManaDrain");
        virtual ~ManaDrain();
};

#endif // MANADRAIN_H
