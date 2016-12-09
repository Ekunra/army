#ifndef SOLDIER_H
#define SOLDIER_H

#include <iostream>
#include "../Unit.h"

class Soldier : public Unit {
    public:
        Soldier(const std::string& name, int hitPoints=100, int damage=20, const std::string& title="Soldier", StateEnum uEnum=SOLDIER);
        virtual ~Soldier();

        virtual void attack(Unit* enemy);
};

std::ostream& operator<<(std::ostream& out, const Soldier& soldier);

#endif // SOLDIER_H
