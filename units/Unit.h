#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include "../states/States.h"
#include "../abilities/BaseAbility.h"
#include "../attack/BaseAttack.h"
#include "../attack/BaseCounterAttack.h"
#include "../cast/BaseCast.h"
#include "../observe/Observable.h"

template <class Type> class BaseAbility;
template <class Type> class BaseAttack;
template <class Type> class BaseCounterAttack;
template <class Type> class Observable;

template <class Type>
class Unit : public Observable<Type> {
    protected:
        std::string* name;
        States<Type>* states;
        States<Type>* altStates;
        BaseAbility<Type>* primaryAbility;
        BaseAbility<Type>* secondaryAbility;
        BaseAttack<Type>* baseAttack;
        BaseCounterAttack<Type>* baseCounterAttack;


    public:
        Unit(const std::string& name,
                States<Type>* states,
                States<Type>* altStates,
                BaseAbility<Type>* priAbility,
                BaseAbility<Type>* secAbility,
                BaseAttack<Type>* baseAttack,
                BaseCounterAttack<Type>* baseCounterAttack);
        virtual ~Unit();

        bool isAlive();
        void ensureIsAlive();

        const LimitedField<Type>* getHealth() const;
        const Damage<Type>* getDamageObj() const;
        const Defence* getDefenceObj() const;
        const States<Type>* getStates() const;
        const States<Type>* getAltStates() const;
        const BaseAbility<Type>* getPrimaryAbility() const;
        const BaseAbility<Type>* getSecondaryAbility() const;
        LimitedField<Type>& getHealthField();
        States<Type>* getStatesAddress();
        States<Type>* getAltStatesAddress();

        const Type& getHitPoints() const;
        const Type& getHitPointsLimit() const;
        const Type& getMaxDmg() const;
        const Type& getMinDmg() const;
        const Type& getLastDmg() const;
        const UnitEnum& getUEnum() const;
        const UnitEnum& getUType() const;
        const std::string& getTitle() const;
        const std::string& getName() const;

        Type getDamage();

        void setStates(States<Type>* newStates);
        void setAltStates(States<Type>* newAltStates);
        void setAttack(BaseAttack<Type>* newAttack);
        void setCounterAttack(BaseCounterAttack<Type>* newCounterAttack);
        void setPrimaryAbility(BaseAbility<Type>* newPrimaryAbility);
        void setSecondaryAbility(BaseAbility<Type>* newSecondaryAbility);

        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);

        virtual void takeDamage(Unit* enemy);
        virtual void takeCADamage(Unit* enemy);

        virtual void takeMagic(DDTSpell<Type>* spell);
        virtual void takeMagic(HTSpell<Type>* spell);

        virtual void usePrimaryAbility(Unit<Type>* enemy);
        virtual void useSecondaryAbility();

        // Observable
        // virtual void attachObserver() = 0;
        // virtual void dettachObserver() = 0;
        // virtual void notifyObserver() = 0;
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const Unit<Type>& unit);

#endif // UNIT_H
