#ifndef STATES_H
#define STATES_H

#include <iostream>
#include "StateEnum.cpp"
#include "../Exceptions.h"

class States {
    protected:
        int hitPoints;
        int hitPointsLimit;
        int damage;
        StateEnum uEnum;
        std::string title;

        void applyDamage(int pain);

    public:
        States(int hp, int damage, const std::string& title="Default", StateEnum uEnum=ZERO);
        virtual ~States();

        const int getHitPoints() const;
        const int getHitPointsLimit() const;
        const int getDamage() const;
        const std::string& getTitle() const;
        const StateEnum getUEnum() const;

        virtual void takeDamage(States* enemy);
        virtual void takeCADamage(States* enemy);

        virtual void takeMagicDamage(int dmg);
        virtual void addHitPoints(int hp);
};

#endif // STATES_H
