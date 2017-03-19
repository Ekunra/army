#include "VampireStates.h"

template <class Type>
VampireStates<Type>::VampireStates ( LimitedField<Type>* health,
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
    out << FO_B_RED;
    out << vampireStates.getTitle() << FO_RESET;
    out << ' ';
    out << *vampireStates.getHealth();
    out << FO_D_GREY << " | " << FO_RESET;
    out << *vampireStates.getDamageObj();
    return out;
}

template std::ostream& operator<<(std::ostream& out, const VampireStates<int>& states);
template std::ostream& operator<<(std::ostream& out, const VampireStates<double>& states);
template std::ostream& operator<<(std::ostream& out, const VampireStates<float>& states);
