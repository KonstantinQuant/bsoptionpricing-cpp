//
// Created by Konstantin Kuchenmeister on 07/27/2021
// 
// Option.h
//

#ifndef QUANTNET_HW_OPTION_H
#define	QUANTNET_HW_OPTION_H

#include "OptionType.h"

/// <summary>
/// The option class is an abstract base class for financial options. It features option attributes and numerical methods, common to European as well as American options.
/// </summary>
class Option {

protected:

	/// <summary>
	/// The type of the option, either call or put.
	/// </summary>
	OptionType type;
	/// <summary>
	/// The expiry time / maturity of the option.
	/// </summary>
	double T;
	/// <summary>
	/// The strike price of the option.
	/// </summary>
	double K;
	/// <summary>
	/// The volatility of the option.
	/// </summary>
	double sig;
	/// <summary>
	/// The risk-free interest rate of the option.
	/// </summary>
	double r;
	/// <summary>
	/// The price of the underlying stock.
	/// </summary>
	double S;
	/// <summary>
	/// The cost of carry.
	/// </summary>
	double b; // Cost of carry

public:

	// Constructors and Destructor:

	/// <summary>
	/// Default constructor for an option. Creates an option object with zero values.
	/// </summary>
	Option();
	/// <summary>
	/// Custom constructor for an option, that constructs an option object with specified values.
	/// </summary>
	Option(double newT, double newK, double newSig, double newR, double S, double newB, OptionType newType);
	/// <summary>
	/// Copy constructor for the option.
	/// </summary>
	Option(const Option& sourceOption);
	/// <summary>
	/// Destructs and option object.
	/// </summary>
	virtual ~Option();

	// Getters:

	/// <summary>
	/// Getter for the expiry time.
	/// </summary>
	/// <returns>Returns the double value of the expiry time.</returns>
	double getT() const;
	/// <summary>
	/// Getter for the strike price.
	/// </summary>
	/// <returns>Returns the double value of the strike price.</returns>
	double getK() const;
	/// <summary>
	/// Getter for the volatility.
	/// </summary>
	/// <returns>Returns the double value of the volatility.</returns>
	double getSig() const;
	/// <summary>
	/// Getter for the risk free interest rate. 
	/// </summary>
	/// <returns>Returns the double value of the risk free interest rate.</returns>
	double getR() const;
	/// <summary>
	/// Getter for the underlying stock price.
	/// </summary>
	/// <returns>Returns the double value of the underlying stock price.</returns>
	double getS() const;
	/// <summary>
	/// Getter for the cost of carry. Risk free interest rate = cost of carry in the Black-Scholes model.
	/// </summary>
	/// <returns>Returns the double value of the cost of carry.</returns>
	double getB() const;

	// Setters:

	/// <summary>
	/// Sets a new expiry time.
	/// </summary>
	/// <param name="newT">The new expiry time as double.</param>
	void setT(double newT);
	/// <summary>
	/// Sets a new strike price.
	/// </summary>
	/// <param name="newK">The new strike price as double.</param>
	void setK(double newK);
	/// <summary>
	/// Sets a new volatility.
	/// </summary>
	/// <param name="newSig">The new volatility.</param>
	void setSig(double newSig);
	/// <summary>
	/// Sets a new risk free interest rate.
	/// </summary>
	/// <param name="newR">The new risk free interest rate.</param>
	void setR(double newR);
	/// <summary>
	/// Sets a new underlying stock price.
	/// </summary>
	/// <param name="newS">The new underlying stock price.</param>
	void setS(double newS);
	/// <summary>
	/// Sets a new cost of carry.
	/// </summary>
	/// <param name="newB">The new cost of carry.</param>
	void setB(double newB);

	// Operator Overloading: 

	/// <summary>
	/// Allows for the assignment of an existing option object to another one.
	/// </summary>
	Option& operator = (const Option& source);

	// Member functions:

	/// <summary>
	/// Calculates the price of the option with respect to the parameters.
	/// </summary>
	/// <returns>Returns the price of the option as a double.</returns>
	virtual double calculatePrice() const = 0;

	/// <summary>
	/// If conditions are satisfied, this function calculates the respective put price of a call option and vice versa.
	/// </summary>
	/// <returns>Returns the price as a double.</returns>
	virtual double putCallParity() const = 0;

	/// <summary>
	/// Helper function that determines whether the passed option's parameters, and the current parameters satisfy the put call parity.
	/// </summary>
	/// <param name="option">The second option, with which the put call parity requirements are checked.</param>
	/// <returns>Returns a logical true or false based on the satisfication of the requirement.</returns>
	virtual bool putCallParity(const Option& option) const = 0;

	// Option Sensitivities / Greeks:

	/// <summary>
	/// Calculates the delta of an option, which is the partial derivative the price formula with respect to the underlying stock price.
	/// </summary>
	/// <returns>Returns the delta value of the option as a double value.</returns>
	virtual double delta() const = 0;
	/// <summary>
	/// Calculates the gamma of an option, which is the second order partial derivative of the price formula with respect to the underlying stock price.
	/// </summary>
	/// <returns>Returns the gamma value of the option as a double value.</returns>
	virtual double gamma() const = 0;
	/// <summary>
	/// Calculates the theta of an option, which is the negative partial derivative the price formula with respect to the expiry time.
	/// </summary>
	/// <returns>Returns the theta value of the option as a double value.</returns>
	virtual double theta() const = 0;
	/// <summary>
	/// Calculates the vega of an option, which is the partial derivative the price formula with respect to the volatility.
	/// </summary>
	/// <returns>Returns the vega value of the option as a double value.</returns>
	virtual double vega() const = 0;
	virtual double rho() const = 0;
};

#endif