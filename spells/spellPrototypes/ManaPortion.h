#ifndef MANAPORTION_H
#define MANAPORTION_H

#include "../Spell.h"

template <class Type>
class ManaPortion : public Spell<Type> {
    protected:
    public:
        ManaPortion(SpellEnum sEnum=MANAPORTION, SpellEnum sType=MT_MAGIC, Type power=(Type)SPower::MANAPORTION, Type manaCost=(Type)SCost::MANAPORTION, const std::string& spellName="ManaPortion");
        virtual ~ManaPortion();
};

#endif // MANAPORTION_H
