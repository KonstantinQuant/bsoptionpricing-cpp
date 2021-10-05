

#include "PlainEuropeanOption.h"
#include "Common.h"
#include <iostream>

int main() {
	// In my mesh implementations, h refers to the constant increment between monotonically increasing values. (see Common.h)
	std::vector<double> mArr = meshArray(10, 60, 2);

	PlainEuropeanOption batch1c(0.25, 65, 0.30, 0.08, 60, 0.08, OptionType::CALL);
	PlainEuropeanOption batch1p(0.25, 65, 0.30, 0.08, 60, 0.08, OptionType::PUT);

	for (std::vector<double>::const_iterator iter = mArr.begin(); iter != mArr.end(); iter++) {
		batch1c.setS(*iter);
		std::cout << batch1c.calculatePrice() << std::endl;
	}

	return 0;
}