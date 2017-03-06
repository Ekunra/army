#ifndef WEREWOLFSTATES_H
#define WEREWOLFSTATES_H

#include <iostream>
#include "States.h"

template <class Type>
class WerewolfStates : public States<Type> {
    public:
        WerewolfStates();
        virtual ~WerewolfStates();
};

template <class Type>
std::ostream& operator<<(std::ostream& out, const WerewolfStates<Type>& werewolfStates);

#endif // WEREWOLFSTATES_H
