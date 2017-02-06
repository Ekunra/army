#include "SpellCaster.h"

template <class Type>
SpellCaster<Type>::SpellCaster( const std::string& name,
                                SpellCasterStates<Type>* spellCasterStates,
                                States<Type>* states,
                                BaseAbility<Type>* priAbility,
                                BaseAbility<Type>* secAbility,
                                BaseAttack<Type>* baseAttack,
                                BaseCounterAttack<Type>* baseCounterAttack)
                                    : spellBook(new SpellBook<Type>() ),
                                      spellCasterStates(spellCasterStates),
                                      Unit<Type> (  name,
                                                    states,
                                                    priAbility,
                                                    secAbility,
                                                    baseAttack,
                                                    baseCounterAttack ) {
    if ( DEBUG ) {
        std::cout << FO_B_GREEN << "|        + " << FO_RESET;
        std::cout << FO_B << "SpellCaster" << FO_RESET << " instance created." << std::endl;
    }
}
template <class Type>
SpellCaster<Type>::~SpellCaster() {
    delete spellCasterStates;
    delete spellBook;
    if ( DEBUG ) {
        std::cout << FO_B_RED << "  - " << FO_RESET;
        std::cout << "SpellCaster (";
        std::cout << FO_B << Unit<Type>::getTitle() << FO_RESET;
        std::cout << ") instance destructed." << std::endl;
    }
}

template <class Type>
bool SpellCaster<Type>::haveEnoughMana() {}

template <class Type>
const SpellCasterStates<Type>& SpellCaster<Type>::getSpellCasterStates() const {
    return *this->spellCasterStates;
}
template <class Type>
const SpellBook<Type>& SpellCaster<Type>::getSpellBook() const {
    return *this->spellBook;
}

template <class Type>
const Type& SpellCaster<Type>::getMana() const {
    return this->spellCasterStates->getMana();
}
template <class Type>
const Type& SpellCaster<Type>::getManaLimit() const {
    return this->spellCasterStates->getManaLimit();
}

template <class Type>
void SpellCaster<Type>::cast(SpellEnum sEnum, SpellCaster<Type>* someCaster) {}
template <class Type>
void SpellCaster<Type>::cast(SpellEnum sEnum, Unit<Type>* enemy) {}

template class SpellCaster<int>;
template class SpellCaster<double>;
template class SpellCaster<float>;

template <class Type>
std::ostream& operator<<(std::ostream& out, const SpellCaster<Type>& spellCaster) {
    out << *((Unit<Type>*)(&spellCaster));
    out << FO_D_GREY << " | " << FO_RESET;
    out << spellCaster.getSpellCasterStates();
    return out;
};

template std::ostream& operator<<(std::ostream& out, const SpellCaster<int>& spellCaster);
template std::ostream& operator<<(std::ostream& out, const SpellCaster<double>& spellCaster);
template std::ostream& operator<<(std::ostream& out, const SpellCaster<float>& spellCaster);
