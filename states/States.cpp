#include <iostream>
#include "States.h"

States::States(int hp, int damage, const std::string& title)
    : hitPoints(hp), hitPointsLimit(hp), damage(damage), title(title) {
    std::cout << "States created." << std::endl;
}
States::~States() {
    std::cout << "States destructed" << std::endl;
}


void States::receivePain(int pain) {
    if ( pain > this->hitPoints ) {
        this->hitPoints = 0;
        return;
    }
    this->hitPoints -= pain;
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
    this->receivePain(enemy->getDamage());
}
void States::takeCADamage(States* enemy) {
    this->receivePain(enemy->getDamage()/2);
}

void States::takeMagicDamage(int dmg) {
}
void States::addHitPoints(int hp) {
}
