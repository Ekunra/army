#ifndef BLESS_H
#define BLESS_H

#include "../Spell.h"

template <class Type>
class Bless : public Spell<Type> {
    protected:
    public:
        Bless ( SpellEnum sEnum=BLESS,
                Type power=(Type)SPower::BLESS,
                Type manaCost=(Type)SCost::BLESS,
                const std::string& spellName="Bless" );
        virtual ~Bless();
};

#endif // BLESS_H
