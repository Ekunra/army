#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include "../states/States.h"
#include "../abilities/BaseAbility.h"
#include "../attack/BaseAttack.h"
#include "../attack/BaseCounterAttack.h"
#include "../cast/BaseCast.h"

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
        States<Type>* altStates;
        BaseAbility<Type>* primaryAbility;
        BaseAbility<Type>* secondaryAbility;
        BaseAttack<Type>* baseAttack;
        BaseCounterAttack<Type>* baseCounterAttack;

        bool isAlive();

    public:
        Unit(const std::string& name,
                States<Type>* states,
                States<Type>* altStates,
                BaseAbility<Type>* priAbility,
                BaseAbility<Type>* secAbility,
                BaseAttack<Type>* baseAttack,
                BaseCounterAttack<Type>* baseCounterAttack);
        virtual ~Unit();

        void ensureIsAlive();

        const LimitedField<Type>* getHealth() const;
        const Damage<Type>* getDamageObj() const;
        const States<Type>* getStates() const;
        const BaseAbility<Type>* getPrimaryAbility() const;
        const BaseAbility<Type>* getSecondaryAbility() const;

        const Type& getHitPoints() const;
        const Type& getHitPointsLimit() const;
        const Type& getMaxDmg() const;
        const Type& getMinDmg() const;
        const UnitEnum& getUEnum() const;
        const UnitEnum& getUType() const;
        const std::string& getTitle() const;
        const std::string& getName() const;

        Type getDamage();

        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);

        virtual void takeDamage(Unit* enemy);
        virtual void takeCADamage(Unit* enemy);

        virtual void takeMagic(/*DDTSpell* spell*/);
        // virtual void takeMagic(HTSpell* spell);

        virtual void usePrimaryAbility(Unit<Type>* enemy);
        virtual void useSecondaryAbility();
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const Unit<Type>& unit);

#endif // UNIT_H
