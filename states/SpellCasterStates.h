#ifndef SPELLCASTERSTATES_H
#define SPELLCASTERSTATES_H

#include <iostream>
#include "States.h"
#include "limitedfield/LimitedField.h"
#include "../debug.h"
#include "../macro_color.cpp"

template <class Type>
class SpellCasterStates : public States<Type> {
    protected:
        LimitedField<Type>* mana;
    public:
        SpellCasterStates(LimitedField<Type>* health,
                          Damage<Type>* damage,
                          Defence* defence,
                          LimitedField<Type>* mana,
                          const std::string& title="Default",
                          UnitEnum uEnum=UnitEnum::DEFAULT,
                          UnitEnum uType=UnitEnum::DEFAULT);
        virtual ~SpellCasterStates();

        const Type& getMana() const;
        const Type& getManaLimit() const;

        virtual void receiveMana();
        virtual void spendMana();
};

template <class Type>
std::ostream operator<<(std::ostream& out, const SpellCasterStates<Type>& scStates);

#endif // SPELLCASTERSTATES_H
