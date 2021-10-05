
#include "PlainEuropeanOption.h"
#include <iostream>
#include "Common.h"

int main() {
	PlainEuropeanOption batch1c(0.25, 65, 0.30, 0.08, 60, 0.08, OptionType::CALL);
	PlainEuropeanOption batch1p(0.25, 65, 0.30, 0.08, 60, 0.08, OptionType::PUT);

	// Data is now: T, sig, K
	std::vector<std::vector<double>> data = { meshArray(0.1, 0.6, 0.02), meshArray(0.1, 0.6, 0.02), meshArray(10, 60, 2) };

	// By default, the matrix return content will be the price of the option, see common.h for documentation
	std::vector<std::vector<double>> results = modifiedMatrixPricer(batch1c, data, MatrixReturnContent::GAMMA);

	printMatrixPrice(results);

	return 0;
}