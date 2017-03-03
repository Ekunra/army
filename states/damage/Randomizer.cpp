#include "Randomizer.h"

std::unique_ptr<Randomizer> Randomizer::instance(nullptr);

Randomizer::Randomizer() {
    srand(time(NULL));
    if ( DEBUG ) {
        std::cout << "----------------------------\n";
        std::cout << FO_B << " * " << FO_RESET << "instance of ";
        std::cout << FO_B << "Randomizer" << FO_RESET << " created\n";
        std::cout << "----------------------------" << std::endl;
    }
}
Randomizer::~Randomizer() {
    if ( DEBUG ) {
        std::cout << FO_B_RED << " * " << FO_RESET << "instance of ";
        std::cout << FO_B << "Randomizer" << FO_RESET << " deleted." << std::endl;
    }
}

void Randomizer::launch() {
    if ( instance == NULL ) {
        instance.reset(new Randomizer());
    }
}
