#ifndef SPELLCASTER_H
#define SPELLCASTER_H

#include <iostream>
#include "Unit.h"
#include "../spells/SpellBook.h"
#include "../states/SpellCasterStates.h"

template <class Type>
class SpellCaster : public Unit<Type> {
    protected:
        SpellCasterStates<Type>* spellCasterStates;
        SpellBook<Type>* spellBook;

        bool haveEnoughMana();
    public:
        SpellCaster(const std::string& name,
                    SpellCasterStates<Type>* SpellCasterStates,
                    States<Type>* states,
                    BaseAbility<Type>* priAbility,
                    BaseAbility<Type>* secAbility,
                    BaseAttack<Type>* baseAttack,
                    BaseCounterAttack<Type>* baseCounterAttack);
        virtual ~SpellCaster();

        const SpellCasterStates<Type>& getSpellCasterStates() const;
        const SpellBook<Type>& getSpellBook() const;

        const Type& getMana() const;
        const Type& getManaLimit() const;

        virtual void cast(SpellEnum sEnum, SpellCaster<Type>* someCaster);
        virtual void cast(SpellEnum sEnum, Unit<Type>* enemy);
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const SpellCaster<Type>& spellCaster);

#endif // SPELLCASTER_H
