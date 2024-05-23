#include "Fraction.h"

Fraction::Fraction(int numer, int denom) : numerator(numer), denominator(denom) {}

void Fraction::simplify()
{
	int gcf = GCD(this->numerator, this->denominator);
	this->numerator = this->numerator / gcf;
	this->denominator = this->denominator / gcf;
}

int Fraction::GCD(int a, int b)
{
	if (a == 0 || b == 0)
	{
		return a == 0 ? b : a;
	}
	GCD(b, a % b);
}

Fraction operator+(Fraction const& a, Fraction const& b)
{
	Fraction tmp((a.numerator * b.denominator) + 
				(b.numerator * a.denominator),
				a.denominator * b.denominator);
	tmp.simplify();
	return tmp;
}

Fraction operator-(Fraction const& a, Fraction const& b)
{
	Fraction tmp();
}

