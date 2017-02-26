#ifndef HEAL_H
#define HEAL_H

#include "../Spell.h"

template <class Type>
class Heal : public Spell<Type> {
    protected:
    public:
        Heal(SpellEnum sEnum=HEAL, SpellEnum sType=HT_MAGIC, Type power=(Type)SPower::HEAL, Type manaCost=(Type)SCost::HEAL, const std::string& spellName="Heal");
        virtual ~Heal();
};

#endif // HEAL_H
