#include "Soldier.h"

Soldier::Soldier(const std::string& name, int hitPoints, int damage, const std::string& title, StateEnum uEnum)
    : Unit(name, hitPoints, damage, title, uEnum, new BaseAttack(), new BaseCounterAttack()) {}

Soldier::~Soldier() {
    std::cout << "Soldier destructed." << std::endl;
}

void Soldier::attack(Unit* enemy) {
    Unit::attack(enemy);
}

std::ostream& operator<<(std::ostream& out, const Soldier& soldier) {
    const Unit* ptr = &soldier;
    out << *ptr << "\033[37m" << " ]" << "\033[0m";
    // out << (Unit)soldier << "\033[37m" << " ]" << "\033[0m";
}
