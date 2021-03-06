#include "HTSpell.h"

template <class Type>
HTSpell<Type>::HTSpell(SpellEnum sEnum, SpellEnum sType, Type power, Type manaCost, const std::string& spellName)
    : Spell<Type>(sEnum, sType, power, manaCost, spellName) {
    std::cout << "   * +++ HTSpell created" << std::endl;
}
template <class Type>
HTSpell<Type>::HTSpell(const Spell<Type>& prototype)
    : Spell<Type> ( prototype.getSEnum(),
                    prototype.getSType(),
                    prototype.getPower(),
                    prototype.getManaCost(),
                    prototype.getSpellName() ) {
    std::cout << "   * +++ HealthTSpell created with Spell Prototype." << std::endl;
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
    std::cout << *((Spell<Type>*)(&spell));
    return out;
}

template std::ostream& operator<<(std::ostream& out, const HTSpell<int>& spell);
template std::ostream& operator<<(std::ostream& out, const HTSpell<double>& spell);
template std::ostream& operator<<(std::ostream& out, const HTSpell<float>& spell);

