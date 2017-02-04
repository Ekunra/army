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
    public:
        SpellCaster(const std::string& name,
                    SpellCasterStates<Type>* SpellCasterStates,
                    States<Type>* states,
                    BaseAbility<Type>* priAbility,
                    BaseAbility<Type>* secAbility,
                    BaseAttack<Type>* baseAttack,
                    BaseCounterAttack<Type>* baseCounterAttack);
        virtual ~SpellCaster();

        const Type& getMana() const;
        const Type& getManaLimit() const;

        virtual void castDDTMagic(SpellEnum sEnum, Unit<Type>* enemy);
        virtual void castHTMagic(SpellEnum sEnum, Unit<Type>* enemy);
        virtual void castMTMagic(SpellEnum sEnum, SpellCaster* friendly);
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const SpellCaster<Type>& spellCaster);

#endif // SPELLCASTER_H
