#include <iostream>
#include "Unit.h"

Unit::Unit(const std::string& name, int hitPoints, int damage, const std::string& title, StateEnum uEnum, BaseAttack* baseAttack, BaseCounterAttack* baseCounterAttack)
    : states(new States(hitPoints, damage, title, uEnum)), name(new std::string(name)), baseAttack(baseAttack), baseCounterAttack(baseCounterAttack) {
    // this->states = new States(hitPoints, damage, title, uEnum);
    // this->name = new std::string(name);
    // this->baseAttack = new BaseAttack;
    // this->baseCounterAttack = new BaseCounterAttack;
}
Unit::~Unit() {
    delete states;
    delete name;
    delete baseAttack;
    delete baseCounterAttack;
    std::cout << "  Unit destructed." << std::endl;
}

bool Unit::isAlive() {
    return this->states->getHitPoints() > 0;
}
void Unit::ensureIsAlive() {
    std::cout << "Ensure is Alive!!!." << std::endl;
    if ( !this->isAlive() ) {
        throw DeadUnitException();
    }
    std::cout << "   Alive!" <<std::endl;
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
const StateEnum Unit::getUEnum() const {
    return this->states->getUEnum();
}


void Unit::takeDamage(Unit* enemy) {
    std::cout << "      --- " << *this->name 
    << " taking damage from " << enemy->getName() 
    << " in ammount of " << enemy->getDamage() 
    << "." << std::endl;

    if ( this->isAlive() ) {
        this->states->takeDamage(enemy->states);
    }
}
void Unit::takeCADamage(Unit* enemy) {
    this->states->takeCADamage(enemy->states);
}
void Unit::attack(Unit* enemy) {
    this->ensureIsAlive();
    this->baseAttack->attack(this, enemy);
}
void Unit::counterAttack(Unit* enemy) {
    if ( this->isAlive() ) {
        this->baseCounterAttack->counterAttack(this, enemy);
    }
}
// void Unit::takeMagicDamage(int dmg) {}
// void Unit::addHitPints(int dmg) {}


std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << "\033[1m" << unit.getName() << "\033[0m";
    out << "\033[37m" << " [ " << unit.getTitle() << " : " << "\033[0m";
    if ( unit.getHitPoints() == unit.getHitPointsLimit() ) {
        out << "\033[32m" << "HP: " << unit.getHitPoints() << "\033[0m" << "\033[37m" << "/" << "\033[0m" << "\033[32m" << unit.getHitPointsLimit() << "\033[0m";
    } else if ( unit.getHitPoints() < unit.getHitPointsLimit() && unit.getHitPoints() > 0 ) {
        out << "\033[33m" << "HP: " << unit.getHitPoints() << "\033[0m" << "\033[37m" << "/" << "\033[0m" << "\033[33m" << unit.getHitPointsLimit() << "\033[0m";
    } else {
        out << "\033[31m" << "HP: " << "\033[0m" << "\033[1;31m" << unit.getHitPoints() << "\033[0m" << "\033[37m" << "/" << "\033[0m" << "\033[31m" << unit.getHitPointsLimit() << "\033[0m";
    }
    out << "\033[37m" << " DG: " << unit.getDamage() << "\033[0m";
}
