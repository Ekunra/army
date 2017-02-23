#include "BaseCast.h"

template <class Type>
BaseCast<Type>::BaseCast() {
    if ( DEBUG ) {
        std::cout << FO_B_GREEN << "|          + " << FO_RESET;
        std::cout << FO_B << "BaseCast" << FO_RESET <<" instance created" << std::endl;
    }
}
template <class Type>
BaseCast<Type>::~BaseCast() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << "      - " << FO_RESET;
        std::cout << "BaseCast instance deleted." << std::endl;
    }
}

template <class Type>
void BaseCast<Type>::action(SpellEnum sEnum, SpellCaster<Type>* caster, SpellCaster<Type>* target) {
    std::cout << FO_B << caster->getName() << FO_RESET << " will cast ";
    std::cout << FO_B << caster->getSpell(sEnum).getSpellName() << FO_RESET;
    std::cout << " to ";
    std::cout << FO_B << target->getName() << FO_RESET << std::endl;

    if ( sEnum > MT_MAGIC && sEnum < ST_MAGIC ) {
        MTSpell<Type>* newMagic = new MTSpell<Type>(sEnum, caster->getSpell(sEnum).getPower(), caster->getSpell(sEnum).getManaCost(), caster->getSpell(sEnum).getSpellName());
        // friendly->spellCasterStates->receiveMana(newMagic);
    }
}

template <class Type>
void BaseCast<Type>::action(SpellEnum sEnum, SpellCaster<Type>* caster, Unit<Type>* target) {
    std::cout << FO_B << caster->getName() << FO_RESET << " will cast ";
    std::cout << FO_B << caster->getSpell(sEnum).getSpellName() << FO_RESET;
    std::cout << " to ";
    std::cout << FO_B << target->getName() << FO_RESET << std::endl;
}

template class BaseCast<int>;
template class BaseCast<double>;
template class BaseCast<float>;
