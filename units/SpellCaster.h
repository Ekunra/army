#ifndef SPELLCASTER_H
#define SPELLCASTER_H

#include <iostream>
#include "Unit.h"
// #include "../attack/BaseCounterAttack.h"
#include "../cast/BaseCast.h"
#include "../spells/SpellBook.h"
#include "../states/SpellCasterStates.h"

template <class Type>
class BaseCast;

template <class Type>
class BaseAbility;

template <class Type>
class BaseAttack;

template <class Type>
class BaseCounterAttack;

template <class Type>
class SpellCaster : public Unit<Type> {
    protected:
        BaseCast<Type>* baseCast;
        SpellCasterStates<Type>* spellCasterStates;
        SpellBook<Type>* spellBook;


    public:
        SpellCaster(SpellCasterStates<Type>* SpellCasterStates,
                    BaseCast<Type>* baseCast,
                    const std::string& name,
                    States<Type>* states,
                    States<Type>* altStates,
                    BaseAbility<Type>* priAbility,
                    BaseAbility<Type>* secAbility,
                    BaseAttack<Type>* baseAttack,
                    BaseCounterAttack<Type>* baseCounterAttack);
        virtual ~SpellCaster();

        bool haveEnoughMana(Type manaNeeded);
        bool haveSpell(SpellEnum sEnum);

        const SpellCasterStates<Type>& getSpellCasterStates() const;
        const SpellBook<Type>& getSpellBook() const;

        const Type& getMana() const;
        const Type& getManaLimit() const;

        virtual void cast(SpellEnum sEnum, SpellCaster<Type>* targetCaster);
        virtual void cast(SpellEnum sEnum, Unit<Type>* targetUnit);
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const SpellCaster<Type>& spellCaster);

#endif // SPELLCASTER_H
