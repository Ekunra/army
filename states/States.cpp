#include "States.h"

template <class Type>
States<Type>::States(LimitedField<Type>* health,
                    Damage<Type>* damage,
                    Defence* defence,
                    const std::string& title,
                    UnitEnum uEnum,
                    UnitEnum uType)
                        :   health(health),
                            damage(damage),
                            defence(defence),
                            uEnum(new UnitEnum(uEnum)),
                            uType(new UnitEnum(uType)),
                            title(new std::string(title)) {
    if ( DEBUG ) {
        std::cout << FO_B_GREEN << "|    + " << FO_RESET;
        std::cout << FO_B << "States" << FO_RESET <<" created" << std::endl;
    }
}

template <class Type>
States<Type>::~States() {
    delete health;
    delete damage;
    delete defence;
    delete uEnum;
    delete uType;
    if ( DEBUG ) {
        std::cout << FO_B_RED << "      - " << FO_RESET;
        std::cout << "States (" << FO_B << *this->title << FO_RESET << ") deleted." << std::endl;
    }
    delete title;
}


template <class Type>
const LimitedField<Type>* States<Type>::getHealth() const {
    return this->health;
}
template <class Type>
const Damage<Type>* States<Type>::getDamageObj() const {
    return this->damage;
}
template <class Type>
const Defence* States<Type>::getDefence() const {
    return this->defence;
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
const Type& States<Type>::getLastDmg() const {
    return this->damage->getLastDmg();
}


template <class Type>
const UnitEnum& States<Type>::getUEnum() const {
    return *this->uEnum;
}

template <class Type>
const UnitEnum& States<Type>::getUType() const {
    return *this->uType;
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
    if ( DEBUG ) {
        std::cout << "      * states arrived to enemy states->takeDamage()" << std::endl;
    }

    *this->health -= (enemy->getDamage() * this->defence->getDmgDefence() );

    if ( DEBUG ) {
        std::cout << FO_B << "      caused damage is : " << FO_RESET;
        std::cout << "damage(" <<  enemy->getLastDmg() << ") * dCoef(";
        std::cout << this->defence->getDmgDefence() << ") = ";
        std::cout << (enemy->getLastDmg() * this->defence->getDmgDefence()) << std::endl;
        std::cout << "      * enemy's states gave damage and takeDamage() finishing its work." << std::endl;
    }
}

template <class Type>
void States<Type>::takeCADamage(States<Type>* enemy) {
        std::cout << "      * states arrived to enemy states->takeCADamage()" << std::endl;
    *this->health -= (enemy->getDamage()/2);

    if ( DEBUG ) {
        std::cout << FO_B << "      caused CA damage is : " << FO_RESET;
        std::cout << "damage(" <<  enemy->getLastDmg()/2 << ") * dCoef(";
        std::cout << this->defence->getDmgDefence() << ") = ";
        std::cout << ((enemy->getLastDmg()/2) * this->defence->getDmgDefence()) << std::endl;
    }
        std::cout << "      * enemy's states gave damage / 2 and takeCADamage() finishing its work." << std::endl;
}


template <class Type>
void States<Type>::takeMagicEffect(DDTSpell<Type>* spell) {}

template <class Type>
void States<Type>::takeMagicEffect(HTSpell<Type>* spell) {}

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
        case UnitEnum::WIZARD : {
            out << FO_B_BLUE;
            break;
        }
        case UnitEnum::HEALER : {
            break;
        }
        case UnitEnum::PRIEST : {
            break;
        }
        default : {
            out << FO_B;
        }
    }
    out << states.getTitle() << FO_RESET;
    out << ' ';
    out << *states.getHealth();
    out << FO_D_GREY << " | " << FO_RESET;
    out << *states.getDamageObj();
}

template std::ostream& operator<<(std::ostream& out, const States<int>& states);
template std::ostream& operator<<(std::ostream& out, const States<double>& states);
template std::ostream& operator<<(std::ostream& out, const States<float>& states);
