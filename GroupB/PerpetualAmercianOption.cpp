

#include "PerpetualAmericanOption.h"
#include <iostream>

PerpetualAmericanOption::PerpetualAmericanOption() : Option() {
	std::cout << "Perpetual american option has been created using the default constructor." << std::endl;
}

PerpetualAmericanOption::PerpetualAmericanOption(double newT, double newK, double newSig, double newR, double newS, double newB, OptionType newType) : Option(newT, newK, newSig, newR, newS, newB, newType) {
	std::cout << "Perpetual american option has been created using the custom constructor." << std::endl;
}

PerpetualAmericanOption::PerpetualAmericanOption(const PerpetualAmericanOption& amexOption) : Option(amexOption) {
	std::cout << "Perpetual american option has been created using the copy constructor." << std::endl;
}

PerpetualAmericanOption::~PerpetualAmericanOption() {
	std::cout << "Perpetual american option has been destructed." << std::endl;
}

// Member functions:

double PerpetualAmericanOption::calculatePrice() const {
	if (type == OptionType::CALL) {
		double sigSq = sig * sig;
		
		double fac1 = ((b / sigSq) - 0.5) * ((b / sigSq) - 0.5);

		double summand1 = 0.5 - (b / sigSq);
		double summand2 = sqrt(fac1 + ((2*r)/sigSq));

		double y_1 = summand1 + summand2;

		double base1 = ((y_1 - 1) / y_1);
		double base2 = (S / K);

		return pow((base1 * base2), y_1) * (K / (y_1 - 1));
	}
	else {
		double sigSq = sig * sig;

		double fac1 = ((b / sigSq) - 0.5) * ((b / sigSq) - 0.5);

		double summand1 = 0.5 - (b / sigSq);
		double summand2 = sqrt(fac1 + ((2 * r) / sigSq));

		double y_2 = summand1 - summand2;

		double base1 = ((y_2 - 1) / y_2);
		double base2 = (S / K);

		return pow((base1 * base2), y_2) * (K / (1-y_2));
	}

}
double PerpetualAmericanOption::putCallParity() const {
	return true;
}


bool PerpetualAmericanOption::putCallParity(const Option& option) const {
	return 0;
}

// Operator Overloading: 
PerpetualAmericanOption& PerpetualAmericanOption::operator = (const PerpetualAmericanOption& source) {
	if (this == &source) {
		Option::operator=(source);
		return *this;
	}
	else {
		Option::operator=(source);
		double T = source.T;
		double K = source.K;
		double sig = source.sig;
		double r = source.r;
		double S = source.S;
		double b = source.b;
		return *this;
	}
}

// Option Sensitivities / Greeks -> Expand for american options in the future, todo, also more greeks
double PerpetualAmericanOption::delta() const {
	return 0;
}
double PerpetualAmericanOption::gamma() const {
	return 0;
}
double PerpetualAmericanOption::theta() const {
	return 0;
}
double PerpetualAmericanOption::vega() const {
	return 0;
}
double PerpetualAmericanOption::rho() const {
	return 0;
}