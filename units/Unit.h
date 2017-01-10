#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include "../states/States.h"
#include "abilities/BaseAbility.h"
#include "attack/BaseAttack.h"
#include "attack/BaseCounterAttack.h"

template <class Type>
class BaseAbility;

template <class Type>
class BaseAttack;

template <class Type>
class BaseCounterAttack;

template <class Type>
class Unit {
    protected:
        std::string* name;
        States<Type>* states;
        BaseAbility<Type>* baseAbility;
        BaseAttack<Type>* baseAttack;
        BaseCounterAttack<Type>* baseCounterAttack;

        bool isAlive();

    public:
        Unit(const std::string& name,
                States<Type>* states,
                BaseAbility<Type>* baseAbility,
                BaseAttack<Type>* baseAttack,
                BaseCounterAttack<Type>* baseCounterAttack);
        virtual ~Unit();

        const LimitedField<Type>& getHealth() const;
        const Damage<Type>& getDamageObj() const;
        const States<Type>& getStates() const;

        const Type& getHitPoints() const;
        const Type& getHitPointsLimit() const;
        const Type& getMaxDmg() const;
        const Type& getMinDmg() const;
        const UnitEnum& getUEnum() const;
        const UnitEnum& getUState() const;
        const std::string& getTitle() const;
        const std::string& getName() const;

        Type getDamage();

        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);

        virtual void takeDamage(Unit* enemy);
        virtual void takeCADamage(Unit* enemy);

        virtual void takeMagic(/*DDTSpell* spell*/);
        // virtual void takeMagic(HTSpell* spell);

        virtual void bite(Unit* enemy);
        virtual void transform();
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const Unit<Type>& unit);

#endif // UNIT_H
