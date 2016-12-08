#ifndef ROGUE_H
#define ROGUE_H

#include <iostream>
#include "../Unit.h"

class Rogue : public Unit {
    public:
        Rogue(const std::string& name, int hitPoints=80, int damage=30, const std::string& title="Rogue");
        virtual ~Rogue();

        virtual void attack(Unit* enemy);
};

std::ostream& operator<<(std::ostream& out, const Rogue& rogue);

#endif // ROGUE_H
