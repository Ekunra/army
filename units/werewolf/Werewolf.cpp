#include "Werewolf.h"

template <class Type>
Werewolf<Type>::Werewolf(const std::string& name) 
    :  Unit<Type>  (name, 
                    new WerewolfStates<Type>(),
                    new WolfStates<Type>(),
                    NULL/*new BaseAbility<Type>(this)*/,
                    new WerewolfTransformAbility<Type>(this),
                    new BaseAttack<Type>,
                    new BaseCounterAttack<Type>) {
    if ( DEBUG ) {
        std::cout << FO_B_L_GREEN << "---------- ** " << FO_RESET;
        std::cout << FO_B << "Werewolf instance created." << FO_RESET << "\n" << std::endl;
    }
}

template <class Type>
Werewolf<Type>::~Werewolf() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << "-- ** " << FO_RESET;
        std::cout << FO_RED << "Werewolf destructed." << FO_RESET << std::endl;
    }
}

template <class Type>
void Werewolf<Type>::attack(Unit<Type>* enemy) {
    Unit<Type>::attack(enemy);
}


template class Werewolf<int>;
template class Werewolf<double>;
template class Werewolf<float>;

template <class Type>
std::ostream& operator<<(std::ostream& out, const Werewolf<Type>& werewolf) {
    out << ' ' << FO_B << werewolf.getName() << FO_RESET;
    out << FO_D_GREY << " [ " << FO_RESET;
    out << *((Unit<Type>*)(&werewolf));
    out << FO_D_GREY << " ]" << FO_RESET;
    return out;
}

template std::ostream& operator<<(std::ostream& out, const Werewolf<int>& werewolf);
template std::ostream& operator<<(std::ostream& out, const Werewolf<double>& werewolf);
template std::ostream& operator<<(std::ostream& out, const Werewolf<float>& werewolf);
