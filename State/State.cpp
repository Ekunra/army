#include "state.h"

State::State(int hitPoints, int damage, bool isUndead, const std::string& title)
    : hitPoints(hitPoints), hitPointsLimit(hitPoints), damage(damage), isUndead(isUndead), title(title) {}


State::~State() {}

void State::ensureIsAlive() {
    if (hitPoints == 0) {
        throw DeadUnitException();
    }
}

const int State::getHitPoints() const {
    return hitPoints;
}
const int State::getHitPointsLimit() const {
    return hitPointsLimit;
}
const int State::getDamage() const {
    return damage;
}
const std::string& State::getTitle() const {
    return title;
}

void State::setHitPoints(int hp) {
    ensureIsAlive();
    hitPoints = hp;
}
void State::setDamage(int dmg) {
    ensureIsAlive();
    damage = dmg;
}

void State::takeDamage(int dmg) {
    ensureIsAlive();

    if (dmg > hitPoints) {
        hitPoints = 0;
        return;
    }
    hitPoints -= dmg;
}

void State::addHitPoints(int hp) {
    ensureIsAlive();

    int total = hitPoints + hp;
    
    if (total > hitPointsLimit) {
        hitPoints = hitPointsLimit;
        return;
    }
    hitPoints = total;
}
