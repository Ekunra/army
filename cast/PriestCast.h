#ifndef PRIESTCAST_H
#define PRIESTCAST_H

#include <iostream>
#include "BaseCast.h"

template <class Type>
class PriestCast : public BaseCast<Type> {
    public: 
        PriestCast();
        virtual ~PriestCast();

        virtual void action ( SpellEnum sEnum,
                              SpellCaster<Type>* caster,
                              SpellCaster<Type>* target );

        virtual void action ( SpellEnum sEnum,
                              SpellCaster<Type>* caster,
                              Unit<Type>* target );
};

#endif // PRIESTCAST_H
