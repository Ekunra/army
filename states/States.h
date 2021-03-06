#ifndef STATES_H
#define STATES_H

#include <iostream>
#include <memory>
#include "damage/Damage.h"
#include "defence/Defence.h"
#include "limitedfield/LimitedField.h"
#include "../Exceptions.h"
#include "../Properties.h"
#include "../spells/spellTypes/DDTSpell.h"
#include "../spells/spellTypes/HTSpell.h"

template <class Type>
class States {
    protected:
        UnitEnum* uEnum;
        UnitEnum* uType;
        std::string* title;
        LimitedField<Type>* health;
        Damage<Type>* damage;
        Defence* defence;

    public:
        States(LimitedField<Type>* health,
               Damage<Type>* damage,
               Defence* defence,
               const std::string& title="Default",
               UnitEnum uEnum=UnitEnum::DEFAULT,
               UnitEnum uType=UnitEnum::DEFAULT);
        virtual ~States();

        const LimitedField<Type>* getHealth() const;
        const Damage<Type>* getDamageObj() const;
        const Defence* getDefence() const;
        LimitedField<Type>& getHealthField();
        Damage<Type>* getDamageAddress();

        const Type& getHitPoints() const;
        const Type& getHitPointsLimit() const;
        const Type& getMaxDmg() const;
        const Type& getMinDmg() const;
        const Type& getLastDmg() const;
        const UnitEnum& getUEnum() const;
        const UnitEnum& getUType() const;
        const std::string& getTitle() const;

        Type getDamage();

        virtual void takeDamage(States* enemy);
        virtual void takeCADamage(States* enemy);

        virtual void takeMagicEffect(DDTSpell<Type>* spell);
        virtual void takeMagicEffect(HTSpell<Type>* spell);
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const States<Type>& states);

#endif // STATES_H
