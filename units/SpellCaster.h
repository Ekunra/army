#ifndef SPELLCASTER_H
#define SPELLCASTER_H

#include <iostream>
#include "Unit.h"
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
class SpellCasterStates;

template <class Type>
class MTSpell;

template <class Type>
class SpellCaster : public Unit<Type> {
    protected:
        BaseCast<Type>* baseCast;
        SpellCasterStates<Type>* spellCasterStates;
        SpellBook<Type>* spellBook;

        void prepareToCast(SpellEnum sEnum);

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

        const Spell<Type>& getSpell(SpellEnum& sEnum) const;
        const Type& getMana() const;
        const Type& getManaLimit() const;

        virtual void cast(SpellEnum sEnum, SpellCaster<Type>* targetCaster);
        virtual void cast(SpellEnum sEnum, Unit<Type>* targetUnit);

        virtual void takeMagic(MTSpell<Type>* spell);
        virtual void takeMagic(DMTSpell<Type>* spell);
        virtual void spendMana(SpellEnum sEnum);
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const SpellCaster<Type>& spellCaster);

#endif // SPELLCASTER_H
