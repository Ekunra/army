#include "VampireStates.h"

template <class Type>
VampireStates<Type>::VampireStates ()
    : States<Type> ( new LimitedField<Type>( (Type)Hp::VAMPIRE, FieldType::HEALTH ),
                     new Damage<Type>((Type)Dmg::VAMPIRE),
                     new Defence((double)TakeDamageCoef::VAMPIRE,
                                 (double)TakeMagicDamageCoef::VAMPIRE),
                     "Vampire",
                     UnitEnum::VAMPIRE,
                     UnitEnum::EVILSPIRIT) {
    if ( DEBUG ) {
        std::cout << FO_B_GREEN << "|    + " << FO_RESET;
        std::cout << FO_B << "VampireStates" << FO_RESET <<" created" << std::endl;
    }
}

template <class Type>
VampireStates<Type>::~VampireStates() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << "      - " << FO_RESET;
        std::cout << "VampireStates (" << FO_B << *this->title << FO_RESET << ") deleted." << std::endl;
    }
}


template class VampireStates<int>;
template class VampireStates<double>;
template class VampireStates<float>;

template <class Type>
std::ostream& operator<<(std::ostream& out, const VampireStates<Type>& vampireStates) {
    // switch ( states.getUEnum() ) {
    //     case UnitEnum::VAMPIRE : {
            out << FO_B_RED;
    //         break;
    //     }
    //     case UnitEnum::WEREWOLF : {
    //         out << FO_B_RED;
    //         break;
    //     }
    //     case UnitEnum::WOLF : {
    //         out << FO_B_RED;
    //         break;
    //     }
    //     case UnitEnum::WIZARD : {
    //         out << FO_B_BLUE;
    //         break;
    //     }
    //     case UnitEnum::HEALER : {
    //         break;
    //     }
    //     case UnitEnum::PRIEST : {
    //         break;
    //     }
    //     default : {
    //         out << FO_B;
    //     }
    // }
    out << vampireStates.getTitle() << FO_RESET;
    out << ' ';
    out << *vampireStates.getHealth();
    out << FO_D_GREY << " | " << FO_RESET;
    out << *vampireStates.getDamageObj();
}

template std::ostream& operator<<(std::ostream& out, const VampireStates<int>& states);
template std::ostream& operator<<(std::ostream& out, const VampireStates<double>& states);
template std::ostream& operator<<(std::ostream& out, const VampireStates<float>& states);
