#include "MTSpell.h"

template <class Type>
MTSpell<Type>::MTSpell(SpellEnum sEnum, Type power, Type manaCost, const std::string& spellName)
    : Spell<Type>(sEnum, power, manaCost, spellName) {
    std::cout << "   * +++ MTSpell created" << std::endl;
}
template <class Type>
MTSpell<Type>::~MTSpell() {
    std::cout << "   * --- MTSpell destructed" << std::endl;
}

template class MTSpell<int>;
template class MTSpell<double>;
template class MTSpell<float>;

template <class Type>
std::ostream& operator<<(std::ostream& out, const MTSpell<Type>& spell) {
    std::cout << *((Spell<Type>*)(&spell));
    return out;
}

template std::ostream& operator<<(std::ostream& out, const MTSpell<int>& spell);
template std::ostream& operator<<(std::ostream& out, const MTSpell<double>& spell);
template std::ostream& operator<<(std::ostream& out, const MTSpell<float>& spell);
