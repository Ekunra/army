#ifndef SOLDIER_H
#define SOLDIER_H

#include <iostream>
#include "../Unit.h"
#include "../../Properties.h"

template <class Type>
class Soldier : public Unit<Type> {
    public:
        Soldier(const std::string& name,
                int hitPoints=(int)Hp::SOLDIER,
                int damage=(int)Dmg::SOLDIER,
                const std::string& title="Soldier",
                UnitEnum uEnum=UnitEnum::SOLDIER,
                UnitEnum uState=UnitEnum::SOLDIER);
        virtual ~Soldier();

        virtual void attack(Unit<Type>* enemy);
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const Soldier<Type>& soldier);

#endif // SOLDIER_H
