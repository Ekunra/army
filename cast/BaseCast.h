#ifndef BASECAST_H
#define BASECAST_H

#include <iostream>
#include "../debug.h"
#include "../macro_color.cpp"
#include "../Properties.h"
#include "../spells/Spell.h"
#include "../spells/SpellEnum.h"
#include "../units/SpellCaster.h"
#include "../units/Unit.h"
#include "../spells/spellTypes/DDTSpell.h"
#include "../spells/spellTypes/HTSpell.h"
#include "../spells/spellTypes/DMTSpell.h"
#include "../spells/spellTypes/MTSpell.h"


template <class Type>
class Unit;

template <class Type>
class SpellCaster;

template <class Type>
class BaseCast {
    protected:
        Spell<Type> createSpell(SpellEnum sEnum, SpellCaster<Type>* caster, double coef);

    public: 
        BaseCast();
        virtual ~BaseCast();

        virtual void action ( SpellEnum sEnum,
                              SpellCaster<Type>* caster,
                              SpellCaster<Type>* target );

        virtual void action ( SpellEnum sEnum,
                              SpellCaster<Type>* caster,
                              Unit<Type>* target );
};

#endif // BASECAST_H
