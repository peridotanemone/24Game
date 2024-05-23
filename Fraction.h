#ifndef FRACTION_H
#define FRACTION_H

int GCD(int a, int b);

class Fraction {
private:
	int numerator, denominator;

public:
	Fraction(int numer = 0, int denom = 0);

	Fraction simplified();

	friend Fraction operator+(Fraction const& a, Fraction const& b);
	friend Fraction operator-(Fraction const& a, Fraction const& b);
	friend Fraction operator*(Fraction const& a, Fraction const& b);
	friend Fraction operator/(Fraction const& a, Fraction const& b);
};

#endif FRACTION_H