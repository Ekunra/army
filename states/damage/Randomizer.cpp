#include "Randomizer.h"

std::unique_ptr<Randomizer> Randomizer::instance(nullptr);

Randomizer::Randomizer() {
    srand(time(NULL));
    if ( DEBUG ) {
        std::cout << "----------------------------" << std::endl;
        std::cout << FO_B << " * " << FO_RESET << "instance of ";
        std::cout << FO_B << "Randomizer" << FO_RESET << " created" << std::endl;
        std::cout << "----------------------------" << std::endl;
    }
}
Randomizer::~Randomizer() {
    if ( DEBUG ) {
        std::cout << FO_B << " * " << FO_RESET << "instance of ";
        std::cout << FO_B << "Randomizer" << FO_RESET << " deleted." << std::endl;
    }
}

void Randomizer::launch() {
    if ( instance == NULL ) {
        instance.reset(new Randomizer());
    }
}
