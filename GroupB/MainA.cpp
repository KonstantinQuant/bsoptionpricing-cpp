
#include <iostream>
#include "PerpetualAmericanOption.h"

int main() {

	PerpetualAmericanOption batch1c = PerpetualAmericanOption(10000000, 100, 0.1, 0.1, 110, 0.02, OptionType::CALL);
	PerpetualAmericanOption batch1p = PerpetualAmericanOption(10000000, 100, 0.1, 0.1, 110, 0.02, OptionType::PUT);

	std::cout << "Call price: " << batch1c.calculatePrice() << std::endl;
	std::cout << "Put price: " << batch1p.calculatePrice() << std::endl;

	return 0;
}