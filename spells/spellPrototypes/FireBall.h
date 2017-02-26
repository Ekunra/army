#ifndef FIREBALL_H
#define FIREBALL_H

#include "../Spell.h"

template <class Type>
class FireBall : public Spell<Type> {
    protected:
    public:
        FireBall(SpellEnum sEnum=FIREBALL, SpellEnum sType=DDT_MAGIC, Type power=(Type)SPower::FIREBALL, Type manaCost=(Type)SCost::FIREBALL, const std::string& spellName="FireBall");
        virtual ~FireBall();
};

#endif // FIREBALL_H
