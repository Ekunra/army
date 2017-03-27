#include "Priest.h"

template <class Type>
Priest<Type>::Priest(const std::string& name)
    : SpellCaster<Type>(new SpellCasterStates<Type>(
                            new LimitedField<Type>( (Type)Mp::PRIEST,
                                                    FieldType::MANA ),
                            (double)DDTMagicCoef::PRIEST,
                            (double)HTMagicCoef::PRIEST,
                            (double)DMTMagicCoef::PRIEST,
                            (double)MTMagicCoef::PRIEST ),
                        new PriestCast<Type>(),
                        name,
                        new PriestStates<Type>(),
                        nullptr, // altStates;
                        nullptr, // primary Ability;
                        nullptr, // secondary Ability;
                        new PriestAttack<Type>(),
                        new PriestCounterAttack<Type>() ) {

    SpellCaster<Type>::spellBook->insertSpell(FIREBALL, new FireBall<Type>);
    SpellCaster<Type>::spellBook->insertSpell(IMPLOSION, new Implosion<Type>);
    SpellCaster<Type>::spellBook->insertSpell(LIGHTNINGBOLT, new LightningBolt<Type>);
    SpellCaster<Type>::spellBook->insertSpell(HEAL, new Heal<Type>);
    SpellCaster<Type>::spellBook->insertSpell(BLESS, new Bless<Type>);
    SpellCaster<Type>::spellBook->insertSpell(MANAPORTION, new ManaPortion<Type>);
    SpellCaster<Type>::spellBook->insertSpell(MANADRAIN, new ManaDrain<Type>);

    if ( DEBUG ) {
        std::cout << FO_B_L_GREEN << "---------- ** " << FO_RESET;
        std::cout << FO_B << "Priest instance created." << FO_RESET << "\n" << std::endl;
    }
}
template <class Type>
Priest<Type>::~Priest() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << "-- ** " << FO_RESET;
        std::cout << FO_RED << "Priest destructed." << FO_RESET << std::endl;
    }
}

template <class Type>
void Priest<Type>::cast(SpellEnum sEnum, SpellCaster<Type>* targetCaster) {
    if ( Unit<Type>::getUEnum() != UnitEnum::WIZARD ) {
        return;
    }
    std::cout << FO_B << this->getName() << FO_RESET;
    std::cout << "'s cast(SpellEnum, SpellCaster*) received ";
    std::cout << targetCaster->getName() << " for sending it to SpellCaster's::cast" << std::endl;
    SpellCaster<Type>::cast(sEnum, targetCaster);
}
template <class Type>
void Priest<Type>::cast(SpellEnum sEnum, Unit<Type>* targetUnit) {
    if ( Unit<Type>::getUEnum() != UnitEnum::WIZARD ) {
        return;
    }
    std::cout << FO_B << this->getName() << FO_RESET;
    std::cout << "'s cast(SpellEnum, Unit*) received ";
    std::cout << targetUnit->getName() << " for sending it to SpellCaster's::cast" << std::endl;
    SpellCaster<Type>::cast(sEnum, targetUnit);
}

template class Priest<int>;
template class Priest<double>;
template class Priest<float>;

template <class Type>
std::ostream& operator<<(std::ostream& out, const Priest<Type>& priest) {
    out << ' ' << FO_B << priest.getName() << FO_RESET;
    out << FO_D_GREY << " [ " << FO_RESET;
    out << *((SpellCaster<Type>*)(&priest));
    out << FO_D_GREY << " ]" << FO_RESET;
    return out;
}

template std::ostream& operator<<(std::ostream& out, const Priest<int>& priest);
template std::ostream& operator<<(std::ostream& out, const Priest<double>& priest);
template std::ostream& operator<<(std::ostream& out, const Priest<float>& priest);

