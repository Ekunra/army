#include "HTSpell.h"

template <class Type>
HTSpell<Type>::HTSpell(SpellEnum sEnum, Type power, Type manaCost, const std::string& spellName)
    : Spell<Type>(sEnum, power, manaCost, spellName) {
    std::cout << "   * +++ HTSpell created" << std::endl;
}
template <class Type>
HTSpell<Type>::~HTSpell() {
    std::cout << "   * --- HTSpell destructed" << std::endl;
}

template class HTSpell<int>;
template class HTSpell<double>;
template class HTSpell<float>;

template <class Type>
std::ostream& operator<<(std::ostream& out, const HTSpell<Type>& spell) {
    std::cout << *((HTSpell<Type>*)(&spell));
    return out;
}

template std::ostream& operator<<(std::ostream& out, const HTSpell<int>& spell);
template std::ostream& operator<<(std::ostream& out, const HTSpell<double>& spell);
template std::ostream& operator<<(std::ostream& out, const HTSpell<float>& spell);

