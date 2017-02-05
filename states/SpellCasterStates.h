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
        double* damageDTmagicCoef;
        double* healingTmagicCoef;
        double* manaTmagicCoef;
    public:
        SpellCasterStates ( LimitedField<Type>* mana,
                            double damageDTmagicCoef,
                            double healingTmagicCoef,
                            double manaTmagicCoef );
        virtual ~SpellCasterStates();

        const LimitedField<Type>& getManaObj() const;

        const Type& getMana() const;
        const Type& getManaLimit() const;
        const double& getDDTmCoef() const;
        const double& getHTmCoef() const;
        const double& getMTmCoef() const;

        virtual void receiveMana();
        virtual void spendMana();
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const SpellCasterStates<Type>& scStates);

#endif // SPELLCASTERSTATES_H
