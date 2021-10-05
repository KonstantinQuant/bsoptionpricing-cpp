

#ifndef QUANTNET_HW_PERPETUALAMERICANOPTION_H
#define QUANTNET_HW_PERPETUALAMERICANOPTION_H 

#include "Option.h"

class PerpetualAmericanOption : public Option { 
	
public:
	// Constructors and Destructor:
	PerpetualAmericanOption(); 
	PerpetualAmericanOption(double newT, double newK, double newSig, double newR, double newS, double newB, OptionType newType);
	PerpetualAmericanOption(const PerpetualAmericanOption& amexOption);
	~PerpetualAmericanOption();

	// Member functions:
	double calculatePrice() const;
	double putCallParity() const;
	bool putCallParity(const Option& option) const;

	// Operator Overloading: 
	PerpetualAmericanOption& operator = (const PerpetualAmericanOption& source);

	// Option Sensitivities / Greeks
	double delta() const;
	double gamma() const;
	double theta() const;
	double vega() const;
	double rho() const;

};

#endif