
#include "PlainEuropeanOption.h"
#include "iostream"
#include <vector>
#include "Common.h"

int main() {
	PlainEuropeanOption batch1c(0.25, 65, 0.30, 0.08, 60, 0.08, OptionType::CALL);
	PlainEuropeanOption batch1p(0.25, 65, 0.30, 0.08, 60, 0.08, OptionType::PUT);

	// Data is now: T, sig, K (see Common.h for documentation)
	std::vector<std::vector<double>> data = { meshArray(0.1, 0.6, 0.02), meshArray(0.1, 0.6, 0.02), meshArray(10, 60, 2) };

	// the modifiedmatrixpricer will return the price by default, making the return type an optional parameter, see documentation in common.h
	std::vector<std::vector<double>> results = modifiedMatrixPricer(batch1c, data);

	printMatrixPrice(results);

	return 0; 
}