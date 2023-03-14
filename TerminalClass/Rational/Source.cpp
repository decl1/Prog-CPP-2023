#include <iostream>


enum DENOMINATOR_ERROR {zero_d};

int search_NOK(int x, int y) {
	int count = (x < y) ? x : y;

	for (int i = 2; i <= count; i++)
		if (!(x % i) && !(y % i)) return i;
		else return 1;
}

int search_gcd(int a, int b) {
	if (a == b) {
		return a;
	}
	if (a > b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	return search_gcd(a, b - a);
}

class Rational {
protected:
	int numerator, denominator;
public:
	Rational() : numerator(1) , denominator(1) { }
	Rational(int m) : numerator(m), denominator(1) { }
	Rational(int m, int n) { 
		if (m < 0 && n < 0) {
			numerator = abs(m);
			denominator = abs(n);
		}
		else if (m > 0 && n < 0) {
			numerator = -1 * m;
			denominator = abs(n);
		}
		else {
			numerator = m;
			denominator = n;
		}
		if (denominator == 0) {
			throw std::invalid_argument("Uncorrect denuminator. Set 1 at denuminator.");
			denominator = 1;
		}
	}
	Rational(const class Rational& fraction) : numerator(fraction.numerator), denominator(fraction.denominator) {}
	void SimpleDimpleDrob() {
			int temp = search_gcd(numerator, denominator);
			numerator = numerator / temp;
			denominator = denominator / temp;
			delete &temp;
	}
	Rational RationalAdd(const class Rational& b) {
		Rational result;
		if (denominator == b.denominator) {
			result.numerator = numerator + b.numerator;
		}
		else {
			int temp = denominator;
			result.denominator = search_NOK(denominator, b.denominator);
			temp = result.denominator / temp;
			result.numerator = numerator * temp + b.numerator * temp;
			delete &temp;
		}
		result.SimpleDimpleDrob();
		return result;
	}
	Rational RationalMultiply(const class Rational& b) {
		Rational result;
		result.numerator = b.numerator * numerator;
		result.denominator = b.denominator * denominator;
		result.SimpleDimpleDrob();
		return result;
	}
	Rational RationalDivision(const class Rational& b) {
		Rational result;
		result.numerator = numerator * b.denominator;
		result.denominator = denominator * b.numerator;
		result.SimpleDimpleDrob();
		return result;
	}
	
};

class Rationalwithpart : Rational {
	int interger;
public:
	Rationalwithpart() : interger(0), Rational() { }
	Rationalwithpart(int p) : interger(p), Rational() { }
	Rationalwithpart(int p, int m, int n) : Rational(abs(m), abs(n)) {
		if (p < 0 && m < 0 && n < 0) {
			this->interger = -1 * p ;
		}
		else if (p < 0 && m < 0) {
			interger = -1 * p;
			numerator = m;
			denominator = n;
		}
		else {
			interger = p;
			numerator = m;
			denominator = n;
		}
	}
	Rationalwithpart(const class Rational& a) : interger(0), Rational(a) {};

	void SimpleRationalwithpart() {
		SimpleDimpleDrob();
		interger += numerator / denominator;
	}

	Rationalwithpart RationalwithpartAdd(const class Rationalwithpart& a) {
		Rationalwithpart result;
		Rational convertNum(a.denominator * a.interger + numerator, denominator);
		result.RationalAdd(convertNum);
		result.SimpleRationalwithpart();
		return result;
	}
	Rationalwithpart RationalwithpartMultiply(const class Rationalwithpart& a) {
		Rationalwithpart result(RationalMultiply(Rational(a.denominator * a.interger + numerator, denominator)));
		result.SimpleRationalwithpart();
		return result;
	}
	Rationalwithpart RationalwithpartDivision(const class Rationalwithpart& a) {
		Rationalwithpart result(RationalDivision(Rational(a.denominator * a.interger + numerator, denominator)));
		result.SimpleRationalwithpart();
		return result;
	}
};

void main() {


}