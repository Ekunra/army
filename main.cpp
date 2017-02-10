#include <iostream>
#include <memory>
// #include "states/limitedfield/LimitedField.h"
// #include "states/damage/Damage.h"
// #include "states/States.h"
// #include "units/Unit.h"
#include "units/soldier/Soldier.h"
#include "units/rogue/Rogue.h"
#include "units/wizard/Wizard.h"
#include "spells/SpellBook.h"
#include "spells/Spell.h"
#include "states/SpellCasterStates.h"


int main() {
    std::unique_ptr<Soldier<double>> sr1(new Soldier<double>("sr1"));
    std::unique_ptr<Wizard<double>> w1(new Wizard<double>("W1"));
    std::unique_ptr<Soldier<double>> sr2(new Soldier<double>("sr2"));

    std::cout << "------------------------------" << std::endl;

    std::cout << *sr1 << std::endl;
    std::cout << *w1 << std::endl;

    std::cout << "------------------------------" << std::endl;

    // LimitedField<double>* mana = new LimitedField<double>(200, FieldType::MANA);
    // SpellCasterStates<double>* scStates = new SpellCasterStates<double>(mana);

    // delete mana;
    // delete scStates;

    std::cout << "------------------------------" << std::endl;
    std::cout << "------------------------------" << std::endl;

    std::cout << "------------------------------" << std::endl;
    std::cout << "------------------------------" << std::endl;

    std::cout << "------------------------------" << std::endl;
    return 0;
}
