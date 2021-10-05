
#include "PlainEuropeanOption.h"
#include <iostream>

int main() {

	PlainEuropeanOption batch1c(0.5, 100, 0.36, 0.1, 105, 0, OptionType::CALL);
	PlainEuropeanOption batch1p(0.5, 100, 0.36, 0.1, 105, 0, OptionType::PUT);

	std::cout << "Provided testbatch call delta: " << batch1c.delta() << std::endl;
	std::cout << "Provided testbatch put delta: " << batch1p.delta() << std::endl;

	std::cout << "Provided testbatch call gamma: " << batch1c.gamma() << std::endl;
	std::cout << "Provided testbatch put gamma: " << batch1p.gamma() << std::endl;

	return 0;
}