#include <iostream>
#include "LimitedField.h"

int main() {
	LimitedField<int>* f1 = new LimitedField<int>(100);
	LimitedField<int>* f2 = new LimitedField<int>(100);


	std::cout << *f1 << std::endl;
	std::cout << *f2 << std::endl;

	if ( f1 == f2 ) {
		std::cout << "Yes" << std::endl;
	} else {
		std::cout << "NO" << std::endl;

	}

	f1->show(f2);

	std::cout << f1->getValue() << std::endl;
	std::cout << f1->getLimit() << std::endl;


	delete f1;
	delete f2;
	return 0;
}
