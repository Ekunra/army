#include "PriestCast.h"

template <class Type>
PriestCast<Type>::PriestCast() {
    if ( DEBUG ) {
        std::cout << FO_B_GREEN << "|            + " << FO_RESET;
        std::cout << FO_B << "PriestCast" << FO_RESET <<" instance created" << std::endl;
    }
}
template <class Type>
PriestCast<Type>::~PriestCast() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << "        - " << FO_RESET;
        std::cout << "PriestCast instance deleted." << std::endl;
    }
}

template <class Type>
void PriestCast<Type>::action(SpellEnum sEnum, SpellCaster<Type>* caster, SpellCaster<Type>* target) {
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
            double coef = caster->getSpellCasterStates().getDMTmCoef();

            if ( target->getUType() == UnitEnum::EVILSPIRIT ) {
                coef *= 2;
            }

            target->takeMagic(new DMTSpell<Type>(this->createSpell(sEnum, caster, coef)));
            break;
        }
        default : {
            std::cout << "BaseCast::action(sEnum, SpellCaster*, SpellCaster*) forward to BaseCast::action(sEnum, SpellCaster*, Unit*)" << std::endl;
            this->action(sEnum, caster, ((Unit<Type>*)(target)));
        }
    }
}

template <class Type>
void PriestCast<Type>::action(SpellEnum sEnum, SpellCaster<Type>* caster, Unit<Type>* target) {
    if ( caster->getSpell(sEnum).getSType() == MT_MAGIC || caster->getSpell(sEnum).getSType() == DMT_MAGIC ) {
        std::cout << FO_B << " Is not much usefull!!!" << FO_RESET << std::endl;
        return;
    }


    switch ( caster->getSpell(sEnum).getSType() ) {
        case ACT_MAGIC : {
            // std::cout << FO_B << caster->getName() << FO_RESET << " will cast ";
            // std::cout << FO_B << caster->getSpell(sEnum).getSpellName() << FO_RESET;
            // std::cout << " to ";
            // std::cout << FO_B << target->getName() << FO_RESET << std::endl;
            break;
        }
        case DDT_MAGIC : {
            double coef = caster->getSpellCasterStates().getDDTmCoef();

            if ( target->getUType() == UnitEnum::EVILSPIRIT ) {
                coef *= 2;
            }

            target->takeMagic(new DDTSpell<Type>(this->createSpell(sEnum, caster, coef)));
            break;
        }
        case HT_MAGIC : {
            target->takeMagic(new HTSpell<Type>(this->createSpell(sEnum, caster, caster->getSpellCasterStates().getHTmCoef())));
            break;
        }
        default : {}
    }
}

template class PriestCast<int>;
template class PriestCast<double>;
template class PriestCast<float>;
