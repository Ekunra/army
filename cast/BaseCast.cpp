#include "BaseCast.h"

template <class Type>
Spell<Type> BaseCast<Type>::createSpell(SpellEnum sEnum, SpellCaster<Type>* caster, double coef) {
    std::cout << "   we receive " << caster->getSpell(sEnum).getSpellName() << " with spellPower = " << caster->getSpell(sEnum).getPower() << " and coef = " << coef << std::endl;
    std::cout << "   Will be Power: " << caster->getSpell(sEnum).getPower() * coef << std::endl;
    std::cout << "        manaCost: " << caster->getSpell(sEnum).getManaCost() << std::endl;
    std::cout << "            name: " << caster->getSpell(sEnum).getSpellName() << std::endl;
    Spell<Type> spell ( caster->getSpell(sEnum).getSEnum(),
                        caster->getSpell(sEnum).getSType(),
                        caster->getSpell(sEnum).getPower() * coef,
                        caster->getSpell(sEnum).getManaCost(),
                        caster->getSpell(sEnum).getSpellName());
    return spell;
}

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
            // std::cout << FO_B << caster->getName() << FO_RESET << " will cast ";
            // std::cout << FO_B << caster->getSpell(sEnum).getSpellName() << FO_RESET;
            // std::cout << " to ";
            // std::cout << FO_B << target->getName() << FO_RESET << std::endl;
            break;
        }
        case MT_MAGIC : {
            target->takeMagic(new MTSpell<Type>(this->createSpell(sEnum, caster, caster->getSpellCasterStates().getMTmCoef())));
            break;
        }
        case DMT_MAGIC : {
            target->takeMagic(new DMTSpell<Type>(this->createSpell(sEnum, caster, caster->getSpellCasterStates().getDMTmCoef())));
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
            target->takeMagic(new DDTSpell<Type>(this->createSpell(sEnum, caster, caster->getSpellCasterStates().getDDTmCoef())));
            break;
        }
        case HT_MAGIC : {
            std::cout << FO_B << caster->getName() << FO_RESET << " will cast ";
            std::cout << FO_B << caster->getSpell(sEnum).getSpellName() << FO_RESET;
            std::cout << " to ";
            std::cout << FO_B << target->getName() << FO_RESET << std::endl;
            target->takeMagic(new DDTSpell<Type>(this->createSpell(sEnum, caster, caster->getSpellCasterStates().getHTmCoef())));
            break;
        }
        default : {}
    }
}

template class BaseCast<int>;
template class BaseCast<double>;
template class BaseCast<float>;
