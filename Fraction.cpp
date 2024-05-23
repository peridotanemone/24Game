#include <string>

#include "Fraction.h"

Fraction::Fraction(int numer, int denom) : numerator(numer), denominator(denom) {}

std::string Fraction::stringify()
{
	return std::to_string(this->numerator) + '/' + std::to_string(this->denominator);
}

Fraction Fraction::simplified()
{
	int gcf = GCD(this->numerator, this->denominator);
	Fraction tmp(this->numerator / gcf, this->denominator / gcf);
	return tmp;
}

int GCD(int a, int b)
{
	if (a == 0 || b == 0)
	{
		return a == 0 ? b : a;
	}
	return GCD(b, a % b);
}

Fraction operator+(Fraction const& a, Fraction const& b)
{
	Fraction tmp((a.numerator * b.denominator) + 
		(b.numerator * a.denominator),
		a.denominator * b.denominator);
	return tmp.simplified();
}

Fraction operator-(Fraction const& a, Fraction const& b)
{
	Fraction tmp((a.numerator * b.denominator) -
		(b.numerator * a.denominator),
		a.denominator * b.denominator);
	return tmp.simplified();
}

Fraction operator*(Fraction const& a, Fraction const& b)
{
	Fraction tmp(a.numerator * b.numerator, 
		a.denominator * b.denominator);
	return tmp.simplified();
}

Fraction operator/(Fraction const& a, Fraction const& b)
{
	Fraction tmp(a.numerator * b.denominator,
		a.denominator * b.numerator);
	return tmp.simplified();
}