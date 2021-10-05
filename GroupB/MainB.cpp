

#include <iostream>
#include "PerpetualAmericanOption.h"
#include "Common.h"
#include <vector>

int main() {

	std::vector<double> mArr = meshArray(80, 110, 2);

	PerpetualAmericanOption batch1c = PerpetualAmericanOption(10000000, 100, 0.1, 0.1, 110, 0.02, OptionType::CALL);
	PerpetualAmericanOption batch1p = PerpetualAmericanOption(10000000, 100, 0.1, 0.1, 110, 0.02, OptionType::PUT);

	for (std::vector<double>::const_iterator iter = mArr.begin(); iter != mArr.end(); iter++) {
		batch1c.setS(*iter);
		std::cout << batch1c.calculatePrice() << std::endl;
	}

	return 0;
}