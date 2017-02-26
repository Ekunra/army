#include "ACTSpell.h"

template <class Type>
ACTSpell<Type>::ACTSpell(SpellEnum sEnum, SpellEnum sType, Type power, Type manaCost, const std::string& spellName)
    : Spell<Type>(sEnum, sType, power, manaCost, spellName) {
    std::cout << "   * +++ ACTSpell created" << std::endl;
}
template <class Type>
ACTSpell<Type>::~ACTSpell() {
    std::cout << "   * --- ACTSpell destructed" << std::endl;
}

template class ACTSpell<int>;
template class ACTSpell<double>;
template class ACTSpell<float>;

template <class Type>
std::ostream& operator<<(std::ostream& out, const ACTSpell<Type>& spell) {
    std::cout << *((ACTSpell<Type>*)(&spell));
    return out;
}

template std::ostream& operator<<(std::ostream& out, const ACTSpell<int>& spell);
template std::ostream& operator<<(std::ostream& out, const ACTSpell<double>& spell);
template std::ostream& operator<<(std::ostream& out, const ACTSpell<float>& spell);
