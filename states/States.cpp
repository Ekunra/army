#include "States.h"

template <class Type>
States<Type>::States(Type hp, Type damage, const std::string& title, UnitEnum uEnum, UnitEnum uState)
                        :   health(new LimitedField<Type>(hp)),
                            damage(new Damage<Type>(damage)),
                            uEnum(new UnitEnum(uEnum)),
                            uState(new UnitEnum(uState)),
                            title(new std::string(title)) {
    std::cout << "     + States created" << std::endl;
}

template <class Type>
States<Type>::~States() {
    delete health;
    delete damage;
    delete uEnum;
    delete uState;
    std::cout << "    - - States (" << *this->title << ") deleted." << std::endl;
    delete title;
}


template <class Type>
const LimitedField<Type>& States<Type>::getHealth() const {
    return *this->health;
}
template <class Type>
const Damage<Type>& States<Type>::getDamageObj() const {
    return *this->damage;
}


template <class Type>
const Type& States<Type>::getHitPoints() const {
    return this->health->getValue();
}

template <class Type>
const Type& States<Type>::getHitPointsLimit() const {
    return this->health->getLimit();
}

template <class Type>
const Type& States<Type>::getMaxDmg() const {
    return this->damage->getMaxDmg();
}

template <class Type>
const Type& States<Type>::getMinDmg() const {
    return this->damage->getMinDmg();
}


template <class Type>
const UnitEnum& States<Type>::getUEnum() const {
    return *this->uEnum;
}

template <class Type>
const UnitEnum& States<Type>::getUState() const {
    return *this->uState;
}

template <class Type>
const std::string& States<Type>::getTitle() const {
    return *this->title;
}

template <class Type>
Type States<Type>::getDamage() {
    std::cout << "      * Damage -> getDamage()" << std::endl;
    return this->damage->getDamage();
    std::cout << "      * Damage -> getDamage() sent Damage" << std::endl;
}

template <class Type>
void States<Type>::takeDamage(States<Type>* enemy) {
        std::cout << "      * states arrived to enemy states" << std::endl;
    *this->health -= enemy->getDamage();

        std::cout << "      * enemy's states gave damage and takeDamage() finishing its work." << std::endl;
}

template <class Type>
void States<Type>::takeCADamage(States<Type>* enemy) {
    *this->health -= (enemy->getDamage()/2);
}


template <class Type>
void States<Type>::takeMagicEffect(/*DDTSpell* spell*/) {}

// template <class Type>
// void States<Type>::takeMagicEffect(/*HTSpell* spell*/) {}

template class States<int>;
template class States<double>;
template class States<float>;

template <class Type>
std::ostream& operator<<(std::ostream& out, const States<Type>& states) {
    switch ( states.getUEnum() ) {
        case UnitEnum::VAMPIRE : {
            out << FO_B_RED;
            break;
        }
        case UnitEnum::WEREWOLF : {
            out << FO_B_RED;
            break;
        }
        case UnitEnum::WOLF : {
            out << FO_B_RED;
            break;
        }
        default : {
            out << FO_B;
        }
    }
    out << states.getTitle() << FO_RESET;
    out << ' ';
    out << states.getHealth();
    out << FO_GREY << " | " << FO_RESET;
    out << states.getDamageObj();
}

template std::ostream& operator<<(std::ostream& out, const States<int>& states);
template std::ostream& operator<<(std::ostream& out, const States<double>& states);
template std::ostream& operator<<(std::ostream& out, const States<float>& states);
