#include "Rogue.h"

template <class Type>
Rogue<Type>::Rogue(const std::string& name) 
    :  Unit<Type> ( name, 
                    new States<Type>(new LimitedField<Type>((Type)Hp::ROGUE, FieldType::HEALTH),
                                     new Damage<Type>((Type)Dmg::ROGUE),
                                     new Defence((double)TakeDamageCoef::ROGUE,
                                                 (double)TakeMagicDamageCoef::ROGUE),
                                     "Rogue",
                                     UnitEnum::ROGUE,
                                     UnitEnum::ALIVE),
                    nullptr,
                    NULL/*new BaseAbility<Type>(this)*/,
                    NULL,
                    new RogueAttack<Type>,
                    new BaseCounterAttack<Type>) {
    if ( DEBUG ) {
        std::cout << FO_B_L_GREEN << "---------- ** " << FO_RESET << FO_B << "Rogue instance created." << FO_RESET << std::endl;
    }
}

template <class Type>
Rogue<Type>::~Rogue() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << "-- ** " << FO_RESET;
        std::cout << FO_RED << "Rogue destructed." << FO_RESET << std::endl;
    }
}

template <class Type>
void Rogue<Type>::attack(Unit<Type>* enemy) {
    Unit<Type>::attack(enemy);
}

template class Rogue<int>;
template class Rogue<double>;
template class Rogue<float>;

template <class Type>
std::ostream& operator<<(std::ostream& out, const Rogue<Type>& rogue) {
    out << ' ' << FO_B << rogue.getName() << FO_RESET;
    out << FO_D_GREY << " [ " << FO_RESET;
    out << *((Unit<Type>*)(&rogue));
    out << FO_D_GREY << " ]" << FO_RESET;
    return out;
}

template std::ostream& operator<<(std::ostream& out, const Rogue<int>& rogue);
template std::ostream& operator<<(std::ostream& out, const Rogue<double>& rogue);
template std::ostream& operator<<(std::ostream& out, const Rogue<float>& rogue);
