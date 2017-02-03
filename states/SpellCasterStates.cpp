#include "SpellCasterStates.h"

template <class Type>
SpellCasterStates<Type>::SpellCasterStates
                (LimitedField<Type>* health,
                 Damage<Type>* damage,
                 Defence* defence,
                 LimitedField<Type>* mana,
                 const std::string& title,
                 UnitEnum uEnum,
                 UnitEnum uType)
                          : States<Type>(health, damage, defence, title, uEnum, uType),
                            mana(mana) {}
template <class Type>
SpellCasterStates<Type>::~SpellCasterStates() {}

template <class Type>
const Type& SpellCasterStates<Type>::getMana() const {
    return this->mana->getValue();
}
template <class Type>
const Type& SpellCasterStates<Type>::getManaLimit() const {
    return this->mana->getLimit();
}

template <class Type>
void SpellCasterStates<Type>::receiveMana() {}
template <class Type>
void SpellCasterStates<Type>::spendMana() {}

template class SpellCasterStates<int>;
template class SpellCasterStates<double>;
template class SpellCasterStates<float>;

template <class Type>
std::ostream& operator<<(std::ostream& out, const SpellCasterStates<Type>& scStates) {}

template std::ostream& operator<<(std::ostream& out, const SpellCasterStates<int>& scStates);
template std::ostream& operator<<(std::ostream& out, const SpellCasterStates<double>& scStates);
template std::ostream& operator<<(std::ostream& out, const SpellCasterStates<float>& scStates);
