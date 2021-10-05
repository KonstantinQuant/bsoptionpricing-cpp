
#include "PlainEuropeanOption.h"
#include <iostream>


int main() {

	PlainEuropeanOption batch1c(0.25, 65, 0.30, 0.08, 60, 0.08, OptionType::CALL);
	PlainEuropeanOption batch1p(0.25, 65, 0.30, 0.08, 60, 0.08, OptionType::PUT);
	std::cout << "C= " << batch1c.calculatePrice() << " P= " << batch1p.calculatePrice() << std::endl;

	PlainEuropeanOption batch2c(1, 100, 0.20, 0.0, 100, 0.0, OptionType::CALL);
	PlainEuropeanOption batch2p(1, 100, 0.20, 0.0, 100, 0.0, OptionType::PUT);
	std::cout << "C= " << batch2c.calculatePrice()<< " P= " << batch2p.calculatePrice() << std::endl;

	PlainEuropeanOption batch3c(1, 10, 0.50, 0.12, 5, 0.12, OptionType::CALL);
	PlainEuropeanOption batch3p(1, 10, 0.50, 0.12, 5, 0.12, OptionType::PUT);
	std::cout << "C= " << batch3c.calculatePrice() << " P= " << batch3p.calculatePrice() << std::endl;

	PlainEuropeanOption batch4c(30, 100, 0.30, 0.08, 100, 0.08, OptionType::CALL);
	PlainEuropeanOption batch4p(30, 100, 0.30, 0.08, 100, 0.08, OptionType::PUT);
	std::cout << "C= " << batch4c.calculatePrice() << " P= " << batch4p.calculatePrice() << std::endl;

	return 0;
}