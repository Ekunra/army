#include "Berserker.h"

template <class Type>
Berserker<Type>::Berserker(const std::string& name) 
    :  Unit<Type>  (name, 
                    new BerserkerStates<Type>(),
                    nullptr,
                    NULL/*new BaseAbility<Type>(this)*/,
                    NULL,
                    new BaseAttack<Type>,
                    new BaseCounterAttack<Type>) {
    if ( DEBUG ) {
        std::cout << FO_B_L_GREEN << "---------- ** " << FO_RESET;
        std::cout << FO_B << "Berserker instance created." << FO_RESET << "\n" << std::endl;
    }
}

template <class Type>
Berserker<Type>::~Berserker() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << "-- ** " << FO_RESET;
        std::cout << FO_RED << "Berserker destructed." << FO_RESET << std::endl;
    }
}

template <class Type>
void Berserker<Type>::attack(Unit<Type>* enemy) {
    Unit<Type>::attack(enemy);
}


template class Berserker<int>;
template class Berserker<double>;
template class Berserker<float>;

template <class Type>
std::ostream& operator<<(std::ostream& out, const Berserker<Type>& berserker) {
    out << ' ' << FO_B << berserker.getName() << FO_RESET;
    out << FO_D_GREY << " [ " << FO_RESET;
    out << *((Unit<Type>*)(&berserker));
    out << FO_D_GREY << " ]" << FO_RESET;
    return out;
}

template std::ostream& operator<<(std::ostream& out, const Berserker<int>& soldier);
template std::ostream& operator<<(std::ostream& out, const Berserker<double>& soldier);
template std::ostream& operator<<(std::ostream& out, const Berserker<float>& soldier);
