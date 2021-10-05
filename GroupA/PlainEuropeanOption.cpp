//
// Created by Konstantin Kuchenmeister on 07/29/2021
// 
// PlainEuropeanOption.cpp
// 
// Implements the functionality previously defined in the PlainEuropeanOption.h file.
//
#include "PlainEuropeanOption.h"
#include <iostream>
#include "Common.h"

// Constructors and Destructor:
PlainEuropeanOption::PlainEuropeanOption() : Option()  {
	std::cout << "Plain european option has been created using the default constructor." << std::endl;
}

PlainEuropeanOption::PlainEuropeanOption(double newT, double newK, double newSig, double newR, double newS, double newB, OptionType newType) : Option(newT, newK, newSig, newR, newS, newB, newType) {
	std::cout << "Plain european option has been created using the custom constructor." << std::endl;
}

PlainEuropeanOption::PlainEuropeanOption(const PlainEuropeanOption& eurOption) : Option(eurOption) {
	std::cout << "Plain european option has been created using the copy constructor." << std::endl;
}

PlainEuropeanOption::~PlainEuropeanOption() {
	std::cout << "Plain european option has been destructed." << std::endl;
}

// Operator overloading
PlainEuropeanOption& PlainEuropeanOption::operator = (const PlainEuropeanOption& source) {
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

// Member functions:
double PlainEuropeanOption::calculatePrice() const {
	double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / (sig * sqrt(T));
	double d2 = d1 - (sig * sqrt(T));

	if (type == OptionType::CALL) return (S * exp((b - r) * T) * N(d1)) - (K * exp(-r * T) * N(d2));
	else return ((K * exp(-r * T)) * N(-d2)) - S * exp((b - r) * T) * N(-d1);
}


double PlainEuropeanOption::putCallParity() const {
	if (type == OptionType::CALL) return (-S + calculatePrice() + K * exp(-r * T));
	else return (S + calculatePrice() - K * exp(-r * T));
}

bool PlainEuropeanOption::putCallParity(const Option& option) const {
	return (K == option.getK() && T == option.getT());
}

double PlainEuropeanOption::delta() const {
	double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / (sig * sqrt(T));

	if (type == OptionType::CALL) return exp((b - r) * T) * N(d1);
	else return exp((b - r) * T) * (N(d1) - 1);
}
double PlainEuropeanOption::gamma() const {
	double d1 = (log(S / K) + (b + (sig * sig) * 0.5) * T) / (sig * sqrt(T));

	return (n(d1) * exp((b - r) * T)) / (S * sig * sqrt(T));
}

/*
double PlainEuropeanOption::theta() const {
	return 0; //TODO
}
double PlainEuropeanOption::vega() const {
	return 0; //TODO
}
double PlainEuropeanOption::rho() const {
	return 0; //TODO
}
*/
double PlainEuropeanOption::approximateDelta(double h) const {
	PlainEuropeanOption copy1 = *this;
	PlainEuropeanOption copy2 = *this;

	copy1.setS(S + h);
	copy2.setS(S - h);
	return (copy1.calculatePrice() - copy2.calculatePrice()) / (2 * h);
}

double PlainEuropeanOption::approximateGamma(double h) const {
	PlainEuropeanOption copy1(*this);
	PlainEuropeanOption copy2(*this);

	copy1.setS(S + h);
	copy2.setS(S - h);
	return ((copy1.calculatePrice() - 2 * this->calculatePrice() + copy2.calculatePrice()) / (h*h));
}