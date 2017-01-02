#ifndef STATES_H
#define STATES_H

#include <iostream>
#include "../Exceptions.h"
#include "limitedfield/LimitedField.h"
#include "damage/Damage.h"

class States {
    protected:
        LimitedField<double>* health;
        Damage<double>* damage;
        UnitEnum uEnum;
        UnitEnum uState;
        std::string title;

    public:
        States(int hp, int damage, const std::string& title="Default", UnitEnum uEnum=UnitEnum::DEFAULT, UnitEnum state=UnitEnum::DEFAULT);
        virtual ~States();

        const int getHitPoints() const;
        const int getHitPointsLimit() const;
        const int getDamage() const;
        const UnitEnum getUEnum() const;
        const UnitEnum getState() const;
        const std::string& getTitle() const;
};

#endif // STATES_H
