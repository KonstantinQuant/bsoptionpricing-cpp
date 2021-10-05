# Black-Scholes-Merton Option Pricing Application 

Author: Konstantin Kuchenmeister


This project features a Black-Scholes-Merton Option Pricing Application for European as well as Perpetual American Options

## GroupA Overview:
- BSM call and put pricing for European Options, with tests.
- Put-call parity 
- Option pricing calculation for monotonically increasing range of underlying values of the spot price, implemented using a custom mesh array.
- Extended mesher for i) expiry time ii) volatility and a third arbitrary option parameter.
- Calculation of Greeks for the options (i.e. gamma, delta, rho, vega).
- Extended matrix pricer to input a matrix of option parameters which returns delta or gamma as result


