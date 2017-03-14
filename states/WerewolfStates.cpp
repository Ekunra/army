#include "WerewolfStates.h"

template <class Type>
WerewolfStates<Type>::WerewolfStates ( LimitedField<Type>* health,
                                       Damage<Type>* damage,
                                       Defence* defence,
                                       const std::string& title,
                                       UnitEnum uEnum,
                                       UnitEnum uType )
    : States<Type> ( health,
                     damage,
                     defence,
                     title,
                     uEnum,
                     uType ) {
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
