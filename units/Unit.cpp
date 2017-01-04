#include "Unit.h"



template <class Type>
Unit<Type>::Unit(const std::string& name,
                    States<Type>* states/*,
                    BaseAbility* baseAbility,
                    BaseAttack* baseAttack,
                    BaseCounterAttack* baseCounterAttack*/)
                            : states(states) {}

template <class Type>
Unit<Type>::~Unit() {
    delete states;
    // delete baseAbility;
    // delete baseAttack;
    // delete baseCounterAttack;
    std::cout << "      Unit instance deleted." << std::endl;
}


template <class Type>
bool Unit<Type>::isAlive() {}


template <class Type>
const Type& Unit<Type>::getHitPoints() const {}

template <class Type>
const Type& Unit<Type>::getHitPointsLimit() const {}

template <class Type>
const Type& Unit<Type>::getMaxDmg() const {}

template <class Type>
const Type& Unit<Type>::getMinDmg() const {}

template <class Type>
const UnitEnum& Unit<Type>::getUEnum() const {}

template <class Type>
const UnitEnum& Unit<Type>::getUState() const {}

template <class Type>
const std::string& Unit<Type>::getTitle() const {}


template <class Type>
Type Unit<Type>::getDamage() {}


template <class Type>
void Unit<Type>::attack(Unit* enemy) {}

template <class Type>
void Unit<Type>::counterAttack(Unit* enemy) {}


template <class Type>
void Unit<Type>::takeDamage(Unit* enemy) {}

template <class Type>
void Unit<Type>::takeCADamage(Unit* enemy) {}


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
std::ostream& operator<<(std::ostream& out, const Unit<Type>& unit) {}

template std::ostream& operator<<(std::ostream& out, const Unit<int>& unit);
template std::ostream& operator<<(std::ostream& out, const Unit<double>& unit);
template std::ostream& operator<<(std::ostream& out, const Unit<float>& unit);
