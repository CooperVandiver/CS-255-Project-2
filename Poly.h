#ifndef POLY_H
#define POLY_H

#include <cmath>
#include <iostream>
using namespace std;

const unsigned int MAX = 21;

class Poly{
	int terms[MAX];

public:
	Poly(); //works
	double Eval(double x); //works
	void Reset(); //works
	void operator+=(const Poly& p);
	void Derivative(); //works
	friend istream& operator>>(istream& is, Poly& p); //works
	friend ostream& operator<<(ostream& os, const Poly& p); //works
	friend Poly operator+(const Poly& p1, const Poly& p2); //works
	friend Poly operator*(const Poly& p1, const Poly& p2);
};

#endif
