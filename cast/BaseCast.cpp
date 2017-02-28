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
    std::cout << FO_B << "   action \"SpellCaster\" received : " << FO_RESET << caster->getSpell(sEnum).getSpellName() << "\n";
    std::cout << "                                   " << caster->getName() << "\n";
    std::cout << "                                   " << target->getName() << std::endl;
    switch ( caster->getSpell(sEnum).getSType() ) {
        case ACT_MAGIC : {
            std::cout << FO_B << caster->getName() << FO_RESET << " will cast ";
            std::cout << FO_B << caster->getSpell(sEnum).getSpellName() << FO_RESET;
            std::cout << " to ";
            std::cout << FO_B << target->getName() << FO_RESET << std::endl;
            break;
        }
        case MT_MAGIC : {
            MTSpell<Type>* newSpell = new MTSpell<Type>(caster->getSpell(sEnum), *caster);
            target->takeMagic(newSpell);
            break;
        }
        case DMT_MAGIC : {
            DMTSpell<Type>* newSpell = new DMTSpell<Type>(caster->getSpell(sEnum), *caster);
            target->takeMagic(newSpell);
            break;
        }
        default : {
            std::cout << "BaseCast::action(sEnum, SpellCaster*, SpellCaster*) forward to BaseCast::action(sEnum, SpellCaster*, Unit*)" << std::endl;
            this->action(sEnum, caster, ((Unit<Type>*)(target)));
        }
    }
}

template <class Type>
void BaseCast<Type>::action(SpellEnum sEnum, SpellCaster<Type>* caster, Unit<Type>* target) {
    std::cout << FO_B << "   action \"Unit\" received : " << FO_RESET << caster->getSpell(sEnum).getSpellName() << "\n";
    std::cout << "                            " << caster->getName() << "\n";
    std::cout << "                            " << target->getName() << std::endl;
    if ( caster->getSpell(sEnum).getSType() == MT_MAGIC || caster->getSpell(sEnum).getSType() == DMT_MAGIC ) {
        std::cout << FO_B << " Is not much usefull!!!" << FO_RESET << std::endl;
        return;
    }


    switch ( caster->getSpell(sEnum).getSType() ) {
        case ACT_MAGIC : {
            std::cout << FO_B << caster->getName() << FO_RESET << " will cast ";
            std::cout << FO_B << caster->getSpell(sEnum).getSpellName() << FO_RESET;
            std::cout << " to ";
            std::cout << FO_B << target->getName() << FO_RESET << std::endl;
            break;
        }
        case DDT_MAGIC : {
            std::cout << FO_B << caster->getName() << FO_RESET << " will cast ";
            std::cout << FO_B << caster->getSpell(sEnum).getSpellName() << FO_RESET;
            std::cout << " to ";
            std::cout << FO_B << target->getName() << FO_RESET << std::endl;
            break;
        }
        case HT_MAGIC : {
            std::cout << FO_B << caster->getName() << FO_RESET << " will cast ";
            std::cout << FO_B << caster->getSpell(sEnum).getSpellName() << FO_RESET;
            std::cout << " to ";
            std::cout << FO_B << target->getName() << FO_RESET << std::endl;
            break;
        }
        default : {}
    }
}

template class BaseCast<int>;
template class BaseCast<double>;
template class BaseCast<float>;
