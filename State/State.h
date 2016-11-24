#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "../Exceptions.h"

class State {
    protected:
    	bool isUndead;
        int hitPoints;
        int hitPointsLimit;
        int damage;
        std::string title;

        void ensureIsAlive();

    public:
        State(int hitPoints, int damage, bool isUndead=false, const std::string& title="Default");
        virtual ~State();

        const int getHitPoints() const;
        const int getHitPointsLimit() const;
        const int getDamage() const;
        const std::string& getTitle() const;

        void setHitPoints(int hp);
        void setDamage(int dmg);

        virtual void takeDamage(int dmg);
        virtual void takeMagicalDamage(int dmg);
        virtual void addHitPoints(int hp);
};

#endif // STATE_H