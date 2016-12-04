#include <iostream>
#include "States.h"

States::States(int hp, int damage, const std::string& title)
    : hitPoints(hp), hitPointsLimit(hp), damage(damage), title(title) {
        std::cout << "States created" << std::endl;
}
States::~States() {
    std::cout << "States destructed." << std::endl;
}

void States::isAlive() {
    if ( this->hitPoints == 0 ) {
        throw new DeadUnitException();
    }
}

const int States::getHitPoints() const {
    return this->hitPoints;
}
const int States::getHitPointsLimit() const {
    return this->hitPointsLimit;
}
const int States::getDamage() const {
    return this->damage; 
}
const std::string& States::getTitle() const {
    return this->title;
}

void States::takeDamage(States* enemy) {
    this->isAlive();
}
void States::takeMagicDamage(int dmg) {
    this->isAlive();
}
void States::addHitPoints(int hp) {
    this->isAlive();
}


std::ostream& operator<<(std::ostream& out, const States& states) {
    out << "[ " << states.getTitle() << " : ";
    if ( states.getHitPoints() == states.getHitPointsLimit() ) {
        out << "\033[32m" << "HP: " << states.getHitPoints() << "\033[0m" << "/" << "\033[32m" << states.getHitPointsLimit() << "\033[0m";
    } else if ( states.getHitPoints() < states.getHitPointsLimit() && states.getHitPoints() != 0 ) {
        out << "\033[33m" << "HP: " << states.getHitPoints() << "\033[0m" << "/" << "\033[33m" << states.getHitPointsLimit() << "\033[0m";
    } else {
        out << "\033[31m" << "HP: " << states.getHitPoints() << "\033[0m" << "/" << "\033[31m" << states.getHitPointsLimit() << "\033[0m";
    }
    out << " DG: " << states.getDamage() << " ]";
}
