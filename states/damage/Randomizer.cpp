#include "Randomizer.h"

Randomizer* Randomizer::instance = NULL;

Randomizer::Randomizer() {
    srand(time(NULL));
    if ( DEBUG ) {
        std::cout << FO_B << " ! " << FO_RESET << "instance of ";
        std::cout << FO_B << "randomizer" << FO_RESET << " created" << std::endl;
    }
}
Randomizer::~Randomizer() {
    if ( DEBUG ) {
        std::cout << "Randomizer deleted" << std::endl;
    }
}

void Randomizer::launch() {
    if ( instance == NULL ) {
        instance = new Randomizer();
    }
}
