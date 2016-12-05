#include "Soldier.h"

Soldier::Soldier(const std::string& name, int hitPoints, int damage, const std::string& title)
    : Unit(name, hitPoints, damage, title) {}

Soldier::~Soldier() {
    std::cout << "Soldier destructed." << std::endl;
}

void Soldier::attack(Unit* enemy) {
    Unit::attack(enemy);
}

std::ostream& operator<<(std::ostream& out, const Soldier& soldier) {
    const Unit* ptr = &soldier;
    out << *ptr;
}
