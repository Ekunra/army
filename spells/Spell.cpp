#include "Spell.h"

template <class Type>
Spell<Type>::Spell(SpellEnum sEnum, SpellEnum sType, Type power, Type manaCost, const std::string& spellName)
              : sEnum(new SpellEnum(sEnum)),
                sType(new SpellEnum(sType)),
                power(new Type(power)),
                manaCost(new Type(manaCost)),
                spellName(new std::string(spellName)) {

    if ( DEBUG ) {
        std::cout << FO_B_GREEN << "             | " << FO_RESET;
        std::cout << this->getSpellName() << "'s Spell:: created" << std::endl;
    }

}
template <class Type>
Spell<Type>::Spell(const Spell<Type>& sample)
              : sEnum(new SpellEnum(sample.getSEnum())),
                sType(new SpellEnum(sample.getSType())),
                power(new Type(sample.getPower())),
                manaCost(new Type(sample.getManaCost())),
                spellName(new std::string(sample.getSpellName()))  {
    std::cout << "Spell copyConstructor made its work." << std::endl;
}
template <class Type>
Spell<Type>::~Spell() {
    delete sEnum;
    delete power;
    delete manaCost;

    if ( DEBUG ) {
        std::cout << FO_B_RED << "          - " << FO_RESET << this->getSpellName();
        std::cout << "'s Spell:: destructed" << std::endl;
    }

    delete spellName;
}

template <class Type>
const SpellEnum& Spell<Type>::getSEnum() const {
    return *this->sEnum;
}
template <class Type>
const SpellEnum& Spell<Type>::getSType() const {
    return *this->sType;
}
template <class Type>
const Type& Spell<Type>::getPower() const {
    return *this->power;
}
template <class Type>
const Type& Spell<Type>::getManaCost() const {
    return *this->manaCost;
}
template <class Type>
const std::string& Spell<Type>::getSpellName() const {
    return *this->spellName;
}

template <class Type>
void Spell<Type>::action(SpellCaster<Type>* caster, SpellCaster<Type>* target) {}
template <class Type>
void Spell<Type>::action(SpellCaster<Type>* caster, Unit<Type>* target) {}

template <class Type>
Spell<Type> Spell<Type>::operator=(const Spell& other) {
std::cout << "\" Spell Operator = works\"" << std::endl;
    *this->sEnum = other.getSEnum();
    *this->sType = other.getSType();
    *this->power = other.getPower();
    *this->manaCost = other.getManaCost();
    *this->spellName = other.getSpellName();
    return *this;
}

template class Spell<int>;
template class Spell<double>;
template class Spell<float>;

template <class Type>
std::ostream& operator<<(std::ostream& out, const Spell<Type>& spell) {
    out << spell.getSpellName() << " spell (";
    out << "Type: ";

    switch ( spell.getSType() ) {
        case DDT_MAGIC : {
            out << "damage, ";
            break;
        }
        case HT_MAGIC : {
            out << "heal, ";
            break;
        }
        case MT_MAGIC : {
            out << "mana, ";
            break;
        }
        case ACT_MAGIC : {
            out << "action, ";
            break;
        }
        default : {}
    }

    out << "power: " << spell.getPower() << ", ";
    out << "mana cost: " << spell.getManaCost() << ')';
    return out;
};

template std::ostream& operator<<(std::ostream& out, const Spell<int>& Spell);
template std::ostream& operator<<(std::ostream& out, const Spell<double>& Spell);
template std::ostream& operator<<(std::ostream& out, const Spell<float>& Spell);
