#include "WerewolfStates.h"

template <class Type>
WerewolfStates<Type>::WerewolfStates ()
    : States<Type> ( new LimitedField<Type>( (Type)Hp::WEREWOLF, FieldType::HEALTH ),
                     new Damage<Type>((Type)Dmg::WEREWOLF),
                     new Defence((double)TakeDamageCoef::WEREWOLF,
                                 (double)TakeMagicDamageCoef::WEREWOLF),
                     "Werewolf",
                     UnitEnum::WEREWOLF,
                     UnitEnum::ALIVE) {
    if ( DEBUG ) {
        std::cout << FO_B_GREEN << "|    + " << FO_RESET;
        std::cout << FO_B << "WerewolfStates" << FO_RESET <<" created" << std::endl;
    }
}

template <class Type>
WerewolfStates<Type>::~WerewolfStates() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << "      - " << FO_RESET;
        std::cout << "WerewolfStates (" << FO_B << *this->title << FO_RESET << ") deleted." << std::endl;
    }
}


template class WerewolfStates<int>;
template class WerewolfStates<double>;
template class WerewolfStates<float>;

template <class Type>
std::ostream& operator<<(std::ostream& out, const WerewolfStates<Type>& werewolfStates) {
    out << *((States<Type>*)(&werewolfStates));
    return out;
}

template std::ostream& operator<<(std::ostream& out, const WerewolfStates<int>& werewolfStates);
template std::ostream& operator<<(std::ostream& out, const WerewolfStates<double>& werewolfStates);
template std::ostream& operator<<(std::ostream& out, const WerewolfStates<float>& werewolfStates);
