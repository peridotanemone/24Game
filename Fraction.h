#ifndef FRACTION_H
#define FRACTION_H

#include <string>

int GCD(int a, int b);

class Fraction {
protected:
	int numerator, denominator;

public:
	Fraction(int numer = 0, int denom = 1);

	int getIntValue();
	Fraction simplified();
	std::string stringify();

	void setValues(int n, int d);

	friend Fraction operator+(Fraction const& a, Fraction const& b);
	friend Fraction operator-(Fraction const& a, Fraction const& b);
	friend Fraction operator*(Fraction const& a, Fraction const& b);
	friend Fraction operator/(Fraction const& a, Fraction const& b);
};

#endif FRACTION_H