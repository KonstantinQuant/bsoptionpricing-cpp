//
// Created by Konstantin Kuchenmeister on 07/29/2021
// 
// Option.cpp
// 
// Implements the functionality previously defined in the Option.h file.
//
#include "Option.h"
#include <iostream>

// Constructors and Destructor:
Option::Option() : T{}, K{}, sig{}, r{}, S{}, b{}, type{ OptionType::CALL } {
	std::cout << "Option has been created using the default constructor." << std::endl;
};

Option::Option(double newT, double newK, double newSig, double newR, double newS, double newB, OptionType newType) : T{ newT }, K{ newK }, sig{ newSig }, r{ newR }, S{ newS }, b{ newB }, type{ newType } {
	std::cout << "Option has been created using the custom constructor." << std::endl;

}

Option::Option(const Option& sourceOption) : T{ sourceOption.T }, K{ sourceOption.K }, sig{ sourceOption.sig }, r{ sourceOption.r }, S{ sourceOption.S }, b{ sourceOption.b }, type{ sourceOption.type } {
	std::cout << "Option has been created using the copy constructor." << std::endl;
}

Option::~Option() {
	std::cout << "Option has been destructed" << std::endl;
}

// Getters:
double Option::getT() const {
	return T;
}
double Option::getK() const {
	return K;
}
double Option::getSig() const {
	return sig;
}
double Option::getR() const {
	return r;
}
double Option::getS() const {
	return S;
}

double Option::getB() const {
	return b;
}

// Setters:
void Option::setT(double newT) {
	T = newT;
}
void Option::setK(double newK) {
	K = newK;
}
void Option::setSig(double newSig) {
	sig = newSig;
}
void Option::setR(double newR) {
	r = newR;
}
void Option::setS(double newS) {
	S = newS;
}
void Option::setB(double newB) {
	b = newB;
}

// Operator Overloading: 
Option& Option::operator = (const Option& source) {
	if (this == &source) return *this;

	T = source.T;
	K = source.K;
	sig = source.sig;
	r = source.r;
	S = source.S;
	b = source.b;

	return *this;
}
