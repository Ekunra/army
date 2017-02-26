#ifndef SPELLCASTERSTATES_H
#define SPELLCASTERSTATES_H

#include <iostream>
#include "limitedfield/LimitedField.h"
#include "../debug.h"
#include "../macro_color.cpp"
#include "../spells/SpellEnum.h"
#include "../spells/spellTypes/MTSpell.h"
#include "../spells/spellTypes/DMTSpell.h"
#include "../units/SpellCaster.h"

template <class Type>
class SpellCaster;

template <class Type>
class SpellCasterStates {
    protected:
        LimitedField<Type>* mana;
        double* damageDTmagicCoef;
        double* healingTmagicCoef;
        double* damageMTmagicCoef;
        double* manaTmagicCoef;
    public:
        SpellCasterStates ( LimitedField<Type>* mana,
                            double damageDTmagicCoef,
                            double healingTmagicCoef,
                            double damageMTmagicCoef,
                            double manaTmagicCoef );
        virtual ~SpellCasterStates();

        const LimitedField<Type>& getManaObj() const;

        const Type& getMana() const;
        const Type& getManaLimit() const;
        const double& getDDTmCoef() const;
        const double& getHTmCoef() const;
        const double& getDMTmCoef() const;
        const double& getMTmCoef() const;

        virtual void spendMana(SpellEnum sEnum, SpellCaster<Type>* caster);
        virtual void spendMana(Spell<Type> spell, SpellCaster<Type>* caster);
        virtual void receiveMana(Spell<Type> spell, SpellCaster<Type>* caster);
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const SpellCasterStates<Type>& scStates);

#endif // SPELLCASTERSTATES_H
