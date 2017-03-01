#include "Unit.h"


template <class Type>
Unit<Type>::Unit(const std::string& name,
                    States<Type>* states,
                    States<Type>* altStates,
                    BaseAbility<Type>* priAbility,
                    BaseAbility<Type>* secAbility,
                    BaseAttack<Type>* baseAttack,
                    BaseCounterAttack<Type>* baseCounterAttack)
                          : name(new std::string(name)),
                            states(states),
                            altStates(altStates),
                            primaryAbility(priAbility),
                            secondaryAbility(secAbility),
                            baseAttack(baseAttack),
                            baseCounterAttack(baseCounterAttack) {
    if ( DEBUG ) {
        std::cout << FO_B_GREEN << "|      + " << FO_RESET;
        std::cout << FO_B << "Unit" << FO_RESET << " instance created." << std::endl;
    }
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
    return this->states->getHitPoints() >= 0.01;
}


template <class Type>
Unit<Type>::~Unit() {
    delete name;
    delete states;
    delete altStates;
    delete primaryAbility;
    delete secondaryAbility;
    delete baseAttack;
    delete baseCounterAttack;
    if ( DEBUG ) {
        std::cout << FO_B_RED << "    - " << FO_RESET;
        std::cout << "Unit instance destructed." << std::endl;
    }
}


template <class Type>
void Unit<Type>::ensureIsAlive() {
    std::cout << "Ensure is Alive!!!." << std::endl;
    if ( !this->isAlive() ) {
        throw DeadUnitException("Unit is dead & can't attack more...");
    }
}


template <class Type>
const LimitedField<Type>* Unit<Type>::getHealth() const {
    return this->states->getHealth();
}
template <class Type>
const Damage<Type>* Unit<Type>::getDamageObj() const {
    return this->states->getDamageObj();
}
template <class Type>
const States<Type>* Unit<Type>::getStates() const {
    return this->states;
}
template <class Type>
const BaseAbility<Type>* Unit<Type>::getPrimaryAbility() const {
    return this->primaryAbility;
}
template <class Type>
const BaseAbility<Type>* Unit<Type>::getSecondaryAbility() const {
    return this->secondaryAbility;
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
const UnitEnum& Unit<Type>::getUType() const {
    return this->states->getUType();
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
    if ( !this->isAlive() ) {
        std::cout << "      --- " << this->getName() << " is not alive, attack() aborted." << std::endl;
        return;
    }
    std::cout << FO_B << " ! " << FO_RESET << this->getName() << FO_B << " attacking " << FO_RESET << enemy->getName() << std::endl;;
    this->baseAttack->attack(this, enemy);
}

template <class Type>
void Unit<Type>::counterAttack(Unit* enemy) {
    if ( !this->isAlive() ) {
        std::cout << "      --- " << this->getName() << " is not alive, counterAttack() aborted." << std::endl;
        return;
    }
    std::cout << FO_B << " ! " << FO_RESET << this->getName() << FO_B << " counter-attacking " << FO_RESET << enemy->getName() << std::endl;;
    this->baseCounterAttack->counterAttack(this, enemy);
}


template <class Type>
void Unit<Type>::takeDamage(Unit* enemy) {
    // std::cout << "      --- " << this->getName() << " taking damage." << std::endl;
    if ( this->isAlive() ) {
        // std::cout << "      * isAlive in takeDamage() function." << std::endl;
        this->states->takeDamage(enemy->states);
        // std::cout << "      * this->states->takeDamage(enemy->states) sent states and finishing it's work." << std::endl;
    } else {
        // std::cout << "      --- " << this->getName() << " is not alive & can't take damage." << std::endl;
    }
}

template <class Type>
void Unit<Type>::takeCADamage(Unit* enemy) {
    std::cout << "      --- " << this->getName() << " taking counter-attack damage." << std::endl;
    this->states->takeCADamage(enemy->states);
    std::cout << "      * this->states->takeCADamаage(enemy->states) sent states and finishing it's work." << std::endl;
}


template <class Type>
void Unit<Type>::takeMagic(DDTSpell<Type>* spell) {
    std::cout << "   Unit::takeMagic(" << FO_B << "DDTSpell" << FO_RESET << ") -> received -> " << FO_B << spell->getSpellName() << FO_RESET << std::endl;
    if ( this->isAlive() ) {
        this->states->takeMagicEffect(spell);
    } else {
        delete spell;
    }
}

template <class Type>
void Unit<Type>::takeMagic(HTSpell<Type>* spell) {
    std::cout << "   Unit::takeMagic(" << FO_B << "HTSpell" << FO_RESET << ") -> received -> " << FO_B << spell->getSpellName() << FO_RESET << std::endl;
    if ( this->isAlive() ) {
        this->states->takeMagicEffect(spell);
    } else {
        delete spell;
    }
}


template <class Type>
void Unit<Type>::usePrimaryAbility(Unit<Type>* enemy) {
    if (  this->primaryAbility == NULL ) {
        std::cout << "You have no primaryAbility :D" << std::endl;
        return;
    }
    this->primaryAbility->action(enemy);
}

template <class Type>
void Unit<Type>::useSecondaryAbility() {
    if ( this->secondaryAbility == NULL ) {
        std::cout << "You have no secondaryAbility :D" << std::endl;
        return;
    }
    this->secondaryAbility->action();
}


template class Unit<int>;
template class Unit<double>;
template class Unit<float>;

template <class Type>
std::ostream& operator<<(std::ostream& out, const Unit<Type>& unit) {
    out << *unit.getStates();
    return out;
}

template std::ostream& operator<<(std::ostream& out, const Unit<int>& unit);
template std::ostream& operator<<(std::ostream& out, const Unit<double>& unit);
template std::ostream& operator<<(std::ostream& out, const Unit<float>& unit);
