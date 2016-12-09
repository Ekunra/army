#include "Rogue.h"

Rogue::Rogue(const std::string& name, int hitPoints, int damage, const std::string& title, StateEnum uEnum)
    : Unit(name, hitPoints, damage, title, uEnum) {}
Rogue::~Rogue() {
    std::cout << "Rogue destructed." << std::endl;
}

void Rogue::attack(Unit* enemy) {
    Unit::ensureIsAlive();
    enemy->takeDamage(this);
}

std::ostream& operator<<(std::ostream& out, const Rogue& rogue) {
    const Unit* roguePtr = &rogue;
    out << *roguePtr << "\033[37m" << " ]" << "\033[0m";
}
