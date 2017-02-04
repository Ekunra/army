#ifndef SPELLCASTERSTATES_H
#define SPELLCASTERSTATES_H

#include <iostream>
#include "limitedfield/LimitedField.h"
#include "../debug.h"
#include "../macro_color.cpp"

template <class Type>
class SpellCasterStates {
    protected:
        LimitedField<Type>* mana;
    public:
        SpellCasterStates(LimitedField<Type>* mana);
        virtual ~SpellCasterStates();

        const Type& getMana() const;
        const Type& getManaLimit() const;

        virtual void receiveMana();
        virtual void spendMana();
};

template <class Type>
std::ostream operator<<(std::ostream& out, const SpellCasterStates<Type>& scStates);

#endif // SPELLCASTERSTATES_H
