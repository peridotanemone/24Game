#pragma once
class Fraction {
private:
	int numerator, denominator;

public:
	Fraction(int numer = 0, int denom = 0);

	void simplify();
	int GCD(int a, int b);

	friend Fraction operator+(Fraction const& a, Fraction const& b);
	friend Fraction operator-(Fraction const& a, Fraction const& b);
	friend Fraction operator*(Fraction const& a, Fraction const& b);
	friend Fraction operator/(Fraction const& a, Fraction const& b);
};