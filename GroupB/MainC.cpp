#include <iostream>
#include "PerpetualAmericanOption.h"
#include "Common.h"
#include <vector>

int main() {

	std::vector<double> mArr = meshArray(80, 110, 2);

	PerpetualAmericanOption batch1c = PerpetualAmericanOption(10000000, 100, 0.1, 0.1, 110, 0.02, OptionType::CALL);
	PerpetualAmericanOption batch1p = PerpetualAmericanOption(10000000, 100, 0.1, 0.1, 110, 0.02, OptionType::PUT);

	// Data is now: T, sig, K
	std::vector<std::vector<double>> data = { meshArray(0.1, 0.6, 0.02), meshArray(0.1, 0.6, 0.02), meshArray(10, 60, 2) };

	// By default, the matrix return content will be the price of the option, see common.h for documentation
	std::vector<std::vector<double>> results = modifiedMatrixPricer(batch1c, data);

	printMatrixPrice(results);

	return 0;
}