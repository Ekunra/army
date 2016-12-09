#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include "../states/States.h"

class Unit {
    protected:
        std::string* name;
        States* states;

        bool isAlive();
        void ensureIsAlive();

    public:
        Unit(const std::string& name, int hitPoints, int damage, const std::string& title, StateEnum uEnum);
        virtual ~Unit();

        const std::string& getName() const;
        const int getHitPoints() const;
        const int getHitPointsLimit() const;
        const int getDamage() const;
        const std::string& getTitle() const;
        const StateEnum getUEnum() const;

        virtual void takeDamage(Unit* enemy);
        virtual void takeCADamage(Unit* enemy);
        // virtual void takeMagicDamage(int dmg);
        // virtual void addHitPints(int dmg);

        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);

};

std::ostream& operator<<(std::ostream& out, const Unit& unit);

#endif // UNIT_H
