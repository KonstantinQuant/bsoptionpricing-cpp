# Black-Scholes-Merton Option Pricing Application 

Author: Konstantin Kuchenmeister


This project features a Black-Scholes-Merton Option Pricing Application for European as well as Perpetual American Options

## Note: 
Most of design decisions and best practices can be found inline in the code comments.
The output.txt files for each group feature an exact analysis and document my design decisions.
Most important code is in the Common.h files, an the respective Options class definitions:
1. PlainEuropeanOption.h
2. PlainEuropeanOption.cpp
3. PerpetualAmericanOption.h
4. PerpetualAmericanOption.cpp


## GroupA Overview:
- BSM call and put pricing for European Options, with tests.
- Put-call parity.
- Option pricing calculation for monotonically increasing range of underlying values of the spot price, implemented using a custom mesh array.
- Extended mesher for i) expiry time ii) volatility and a third arbitrary option parameter.
- Calculation of Greeks for the options (i.e. gamma, delta, rho, vega).
- Extended matrix pricer to input a matrix of option parameters which returns delta or gamma as result.
- Approximated option sensitivities using divided differences.

## GroupB Overview:
- Everything from GroupA
- Added support for perpetual American options.
