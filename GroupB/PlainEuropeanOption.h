
#ifndef QUANTNET_HW_PLAINEUROPEANOPTION_H
#define QUANTNET_HW_PLAINEUROPEANOPTION_H

#include "Option.h"

/// <summary>
/// Implements the common abstract base class type Option, to model a plain european option.
/// </summary>
class PlainEuropeanOption : public Option {

public:

	// Constructors and Destructor:
	PlainEuropeanOption();
	PlainEuropeanOption(double newT, double newK, double newSig, double newR, double newS, double newB, OptionType newType);
	PlainEuropeanOption(const PlainEuropeanOption& eurOption);
	~PlainEuropeanOption();

	// Member functions:
	double calculatePrice() const;
	double putCallParity() const;
	bool putCallParity(const Option& option) const;

	// Operator Overloading: 
	PlainEuropeanOption& operator = (const PlainEuropeanOption& source);

	// Option Sensitivities / Greeks
	double delta() const;
	double gamma() const;
	double theta() const;
	double vega() const;
	double rho() const;

	// Approximations:

	/// <summary>
	/// Approximates the delta of a european call or put option using divided differences.
	/// </summary>
	/// <param name="h">Sensitivity value.</param>
	/// <returns>Returns the approximated delta of the option.</returns>
	double approximateDelta(double h) const;
	/// <summary>
	/// Approximates the gamma of a european call or put option using divided differences.
	/// </summary>
	/// <param name="h">Sensitivity value.</param>
	/// <returns>Returns the approximated gamma of the option.</returns>
	double approximateGamma(double h) const;

};

#endif