#include <iostream>
#include "Unit.h"

Unit::Unit(const std::string& name, int hitPoints, int damage, const std::string& title) {
    this->states = new States(hitPoints, damage, title);
    this->name = new std::string(name);
    std::cout << "Unit created." << std::endl;
}
Unit::~Unit() {
    delete states;
    delete name;
    std::cout << "Unit destructed." << std::endl;
}

const std::string& Unit::getName() const {
    return *this->name;
}
const int Unit::getHitPoints() const {
    return this->states->getHitPoints();
}
const int Unit::getHitPointsLimit() const {
    return this->states->getHitPointsLimit();
}
const int Unit::getDamage() const {
    return this->states->getDamage();
}
const std::string& Unit::getTitle() const {
    return this->states->getTitle();
}

void Unit::takeDamage(Unit* enemy) {
    this->states->takeDamage(enemy->states);
}
void Unit::takeMagicDamage(int dmg) {}
void Unit::addHitPints(int dmg) {}

void Unit::attack(Unit* enemy) {}
void Unit::counterAttack(Unit* enemy) {}

std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << "\033[1m" << unit.getName() << "\033[0m";
    out << " [ " << unit.getTitle() << " : ";
    if ( unit.getHitPoints() == unit.getHitPointsLimit() ) {
        out << "\033[32m" << "HP: " << unit.getHitPoints() << "\033[0m" << "/" << "\033[32m" << unit.getHitPointsLimit() << "\033[0m";
    } else if ( unit.getHitPoints() < unit.getHitPointsLimit() && unit.getHitPoints() > 0 ) {
        out << "\033[33m" << "HP: " << unit.getHitPoints() << "\033[0m" << "/" << "\033[33m" << unit.getHitPointsLimit() << "\033[0m";
    } else {
        out << "\033[31m" << "HP: " << "\033[0m" << "\033[1;31m" << unit.getHitPoints() << "\033[0m" << "/" << "\033[31m" << unit.getHitPointsLimit() << "\033[0m";
    }
    out << " DG: " << unit.getDamage() << " ]";
}
