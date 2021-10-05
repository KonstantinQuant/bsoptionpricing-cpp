
#include "PlainEuropeanOption.h"
#include <iostream>
#include "Common.h"

int main() {
	std::vector<double> mArr = meshArray(10, 60, 2);

	PlainEuropeanOption batch1c(0.25, 65, 0.30, 0.08, 60, 0.08, OptionType::CALL);
	PlainEuropeanOption batch1p(0.25, 65, 0.30, 0.08, 60, 0.08, OptionType::PUT);
	
	std::vector<double> callPriceResults;
	std::vector<double> deltaResults;

	for (std::vector<double>::const_iterator iter = mArr.begin(); iter != mArr.end(); iter++) {
		batch1c.setS(*iter);
		deltaResults.push_back(batch1c.delta());
		std::cout << "Delta results: " << batch1c.delta() << " for S: " << *iter << std::endl;
		callPriceResults.push_back(batch1c.calculatePrice());
	}

	return 0;
}