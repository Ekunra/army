#include "SpellCasterStates.h"

template <class Type>
SpellCasterStates<Type>::SpellCasterStates(LimitedField<Type>* mana)
          : mana(mana) {
    if ( DEBUG ) {
        std::cout << FO_B_GREEN << "         + " << FO_RESET;
        std::cout << FO_B << "SpellCasterStates" << FO_RESET <<" created" << std::endl;
    }
}
template <class Type>
SpellCasterStates<Type>::~SpellCasterStates() {
    delete mana;
    if ( DEBUG ) {
        std::cout << FO_B_RED << "      - " << FO_RESET;
        std::cout << "SpellCasterStates deleted." << std::endl;
    }
}

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
