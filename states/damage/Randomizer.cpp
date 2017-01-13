#include "Randomizer.h"

Randomizer* Randomizer::instance = NULL;

Randomizer::Randomizer() {
    srand(time(NULL));
    std::cout << "   + instance of randomizer created" << std::endl;
}
Randomizer::~Randomizer() {
    std::cout << "Randomizer deleted" << std::endl;
}

void Randomizer::launch() {
    if ( instance == NULL ) {
        instance = new Randomizer();
    }
}
