#include "Unit.h"


template <class Type>
Unit<Type>::Unit(const std::string& name,
                    States<Type>* states,
                    BaseAbility<Type>* baseAbility,
                    BaseAttack<Type>* baseAttack,
                    BaseCounterAttack<Type>* baseCounterAttack)
                          : name(new std::string(name)),
                            states(states),
                            baseAbility(baseAbility),
                            baseAttack(baseAttack),
                            baseCounterAttack(baseCounterAttack) {
    std::cout << "      + Unit instance created." << std::endl;
}


template <>
bool Unit<int>::isAlive() {
    std::cout << " - <int>::isAlive() is working." << std::endl;
    return this->states->getHitPoints() > 0;
}
template <>
bool Unit<double>::isAlive() {
    std::cout << " - <double>::isAlive() is working." << std::endl;
    return this->states->getHitPoints() > 0;
}
template <>
bool Unit<float>::isAlive() {
    std::cout << " - <float>::isAlive() is working." << std::endl;
    return this->states->getHitPoints() >= 0.1;
}


template <class Type>
Unit<Type>::~Unit() {
    delete name;
    delete states;
    delete baseAbility;
    delete baseAttack;
    delete baseCounterAttack;
    std::cout << "    - Unit instance destructed." << std::endl;
}


template <class Type>
const LimitedField<Type>& Unit<Type>::getHealth() const {
    return this->states->getHealth();
}
template <class Type>
const Damage<Type>& Unit<Type>::getDamageObj() const {
    return this->states->getDamageObj();
}


template <class Type>
const Type& Unit<Type>::getHitPoints() const {
    return this->states->getHitPoints();
}
template <class Type>
const Type& Unit<Type>::getHitPointsLimit() const {
    return this->states->getHitPointsLimit();
}
template <class Type>
const Type& Unit<Type>::getMaxDmg() const {
    return this->states->getMaxDmg();
}
template <class Type>
const Type& Unit<Type>::getMinDmg() const {
    return this->states->getMinDmg();
}
template <class Type>
const UnitEnum& Unit<Type>::getUEnum() const {
    return this->states->getUEnum();
}
template <class Type>
const UnitEnum& Unit<Type>::getUState() const {
    return this->states->getUState();
}
template <class Type>
const std::string& Unit<Type>::getTitle() const {
    return this->states->getTitle();
}
template <class Type>
const std::string& Unit<Type>::getName() const {
    return *this->name;
}


template <class Type>
Type Unit<Type>::getDamage() {
    this->states->getDamage();
}


template <class Type>
void Unit<Type>::attack(Unit* enemy) {
    this->baseAttack->attack(this, enemy);
}

template <class Type>
void Unit<Type>::counterAttack(Unit* enemy) {
    this->baseCounterAttack->counterAttack(this, enemy);
}


template <class Type>
void Unit<Type>::takeDamage(Unit* enemy) {
    if ( this->isAlive() ) {
        this->states->takeDamage(enemy->states);
    }
}

template <class Type>
void Unit<Type>::takeCADamage(Unit* enemy) {
    this->states->takeCADamage(enemy->states);
}


template <class Type>
void Unit<Type>::takeMagic(/*DDTSpell* spell*/) {}

// template <class Type>
// void Unit<Type>::takeMagic(HTSpell* spell) {}


template <class Type>
void Unit<Type>::bite(Unit* enemy) {}

template <class Type>
void Unit<Type>::transform() {}


template class Unit<int>;
template class Unit<double>;
template class Unit<float>;

template <class Type>
std::ostream& operator<<(std::ostream& out, const Unit<Type>& unit) {
    out << unit.getHealth();
    out << FO_GREY << " | " << FO_RESET;
    out << unit.getDamageObj();
    return out;
}

template std::ostream& operator<<(std::ostream& out, const Unit<int>& unit);
template std::ostream& operator<<(std::ostream& out, const Unit<double>& unit);
template std::ostream& operator<<(std::ostream& out, const Unit<float>& unit);
