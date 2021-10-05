
#include "PlainEuropeanOption.h"
#include <iostream>

int main() {
	PlainEuropeanOption batch1c(0.25, 65, 0.30, 0.08, 60, 0.08, OptionType::CALL);
	PlainEuropeanOption batch1p(0.25, 65, 0.30, 0.08, 60, 0.08, OptionType::PUT);

	if (batch1c.putCallParity(batch1p)) {
		std::cout << "Put-Price for Call 1: " << batch1c.putCallParity() << std::endl;
		std::cout << "Call-Price for Put 1: " << batch1p.putCallParity() << std::endl;
	}
	
}