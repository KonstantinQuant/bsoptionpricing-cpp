
#include "PlainEuropeanOption.h"
#include "Common.h"
#include <iostream>

int main() {

	PlainEuropeanOption batch1c(0.25, 65, 0.30, 0.08, 60, 0.08, OptionType::CALL);

	std::cout << "Exact Delta: " << batch1c.delta() << std::endl;
	std::cout << "Approximated Delta: " << batch1c.approximateDelta(0.001) << std::endl;

	std::cout << "Exact Gamma: " << batch1c.gamma() << std::endl;
	std::cout << "Approximated Gamma: " << batch1c.approximateGamma(0.1) << std::endl;

	return 0;
}