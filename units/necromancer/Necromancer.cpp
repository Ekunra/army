#include "Necromancer.h"

template <class Type>
Necromancer<Type>::Necromancer(const std::string& name)
    : SpellCaster<Type>(new SpellCasterStates<Type>(
                            new LimitedField<Type>( (Type)Mp::NECROMANCER,
                                                    FieldType::MANA ),
                            (double)DDTMagicCoef::NECROMANCER,
                            (double)HTMagicCoef::NECROMANCER,
                            (double)DMTMagicCoef::NECROMANCER,
                            (double)MTMagicCoef::NECROMANCER ),
                        new BaseCast<Type>(),
                        name,
                        new NecromancerStates<Type>(),
                        nullptr, // altState;
                        nullptr, // primary Ability;
                        nullptr, // secondary Ability;
                        new BaseAttack<Type>,
                        new BaseCounterAttack<Type> ) {

    SpellCaster<Type>::spellBook->insertSpell(FIREBALL, new FireBall<Type>);
    SpellCaster<Type>::spellBook->insertSpell(IMPLOSION, new Implosion<Type>);
    SpellCaster<Type>::spellBook->insertSpell(LIGHTNINGBOLT, new LightningBolt<Type>);
    SpellCaster<Type>::spellBook->insertSpell(HEAL, new Heal<Type>);
    SpellCaster<Type>::spellBook->insertSpell(BLESS, new Bless<Type>);
    SpellCaster<Type>::spellBook->insertSpell(MANAPORTION, new ManaPortion<Type>);
    SpellCaster<Type>::spellBook->insertSpell(MANADRAIN, new ManaDrain<Type>);

    if ( DEBUG ) {
        std::cout << FO_B_L_GREEN << "---------- ** " << FO_RESET;
        std::cout << FO_B << "Necromancer instance created." << FO_RESET << "\n" << std::endl;
    }
}
template <class Type>
Necromancer<Type>::~Necromancer() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << "-- ** " << FO_RESET;
        std::cout << FO_RED << "Necromancer destructed." << FO_RESET << std::endl;
    }
}

template <class Type>
void Necromancer<Type>::cast(SpellEnum sEnum, SpellCaster<Type>* targetCaster) {
    if ( Unit<Type>::getUEnum() != UnitEnum::NECROMANCER ) {
        return;
    }
    std::cout << FO_B << this->getName() << FO_RESET;
    std::cout << "'s cast(SpellEnum, SpellCaster*) received ";
    std::cout << targetCaster->getName() << " for sending it to SpellCaster's::cast" << std::endl;
    SpellCaster<Type>::cast(sEnum, targetCaster);
}
template <class Type>
void Necromancer<Type>::cast(SpellEnum sEnum, Unit<Type>* targetUnit) {
    if ( Unit<Type>::getUEnum() != UnitEnum::NECROMANCER ) {
        return;
    }
    std::cout << FO_B << this->getName() << FO_RESET;
    std::cout << "'s cast(SpellEnum, Unit*) received ";
    std::cout << targetUnit->getName() << " for sending it to SpellCaster's::cast" << std::endl;
    SpellCaster<Type>::cast(sEnum, targetUnit);
}

template class Necromancer<int>;
template class Necromancer<double>;
template class Necromancer<float>;

template <class Type>
std::ostream& operator<<(std::ostream& out, const Necromancer<Type>& necromancer) {
    out << ' ' << FO_B << necromancer.getName() << FO_RESET;
    out << FO_D_GREY << " [ " << FO_RESET;
    out << *((SpellCaster<Type>*)(&necromancer));
    out << FO_D_GREY << " ]" << FO_RESET;
    return out;
}

template std::ostream& operator<<(std::ostream& out, const Necromancer<int>& necromancer);
template std::ostream& operator<<(std::ostream& out, const Necromancer<double>& necromancer);
template std::ostream& operator<<(std::ostream& out, const Necromancer<float>& necromancer);

