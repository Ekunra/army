#include "Spell.h"

template <class Type>
Spell<Type>::Spell(SpellEnum sEnum, Type power, Type manaCost, const std::string& spellName)
              : sEnum(new SpellEnum(sEnum)),
                power(new Type(power)),
                manaCost(new Type(manaCost)),
                spellName(new std::string(spellName)) {
    if ( DEBUG ) {
        std::cout << "         + " << this->getSpellName() << "'s Spell:: created" << std::endl;
    }
}
template <class Type>
Spell<Type>::Spell(const Spell<Type>& prototype)
              : sEnum(new SpellEnum(prototype.getSEnum())),
                power(new Type(prototype.getPower())),
                manaCost(new Type(prototype.getManaCost())),
                spellName(new std::string(prototype.getSpellName()))  {
    std::cout << "Spell copyConstructor made its work." << std::endl;
}
template <class Type>
Spell<Type>::~Spell() {
    delete sEnum;
    delete power;
    delete manaCost;

    if ( DEBUG ) {
        std::cout << "         - " << this->getSpellName() << "'s Spell:: destructed" << std::endl;
    }
    delete spellName;
}

template <class Type>
const SpellEnum& Spell<Type>::getSEnum() const {
    return *this->sEnum;
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


template class Spell<int>;
template class Spell<double>;
template class Spell<float>;

template <class Type>
std::ostream& operator<<(std::ostream& out, const Spell<Type>& spell) {
    out << spell.getSpellName() << " spell (";
    out << "power: " << spell.getPower() << ", ";
    out << "mana cost: " << spell.getManaCost() << ')';
    return out;
};

template std::ostream& operator<<(std::ostream& out, const Spell<int>& Spell);
template std::ostream& operator<<(std::ostream& out, const Spell<double>& Spell);
template std::ostream& operator<<(std::ostream& out, const Spell<float>& Spell);
