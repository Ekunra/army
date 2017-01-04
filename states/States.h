#ifndef STATES_H
#define STATES_H

#include <iostream>
#include "../Exceptions.h"
#include "../Properties.h"
#include "damage/Damage.h"
#include "limitedfield/LimitedField.h"

template <class Type>
class States {
    protected:
        UnitEnum* uEnum;
        UnitEnum* uState;
        std::string* title;
        LimitedField<Type>* health;
        Damage<Type>* damage;

    public:
        States(Type hp, Type damage, const std::string& title="Default", UnitEnum uEnum=UnitEnum::DEFAULT, UnitEnum uState=UnitEnum::DEFAULT);
        virtual ~States();

        const Type& getHitPoints() const;
        const Type& getHitPointsLimit() const;
        const Type& getMaxDmg() const;
        const Type& getMinDmg() const;
        const UnitEnum& getUEnum() const;
        const UnitEnum& getUState() const;
        const std::string& getTitle() const;

        Type getDamage();

        virtual void takeDamage(States* enemy);
        virtual void takeCADamage(States* enemy);

        virtual void takeMagicEffect(/*DDTSpell* spell*/);
        // virtual void takeMagicEffect(HTSpell* spell);
};

#endif // STATES_H
