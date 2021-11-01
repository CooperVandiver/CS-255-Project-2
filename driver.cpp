// driver.cpp
// Dr. Janet T. Jenkins
// This is a sample driver program
// Before it is really helpful, you will need to
// have the insertion and extraction operators working
// DO NOT START CODING ANYTHING UNTIL
// THE CONSTRUCTOR METHOD, INPUT AND OUTPUT OPERATORS
// ARE WORKING CORRECTLY

// Feel free to change this main program as you wish.
// You may find it easier to use to read polynomials
// from a file rather than from standard input

#include "Poly.h"
#include <iostream>
#include <fstream>
using namespace std;


void testConstructor(ostream&);
void testInput(istream&, ostream&);
void testReset(istream&, ostream&);
void testEvaluate(istream&, ostream&);
void testAdd(istream&, ostream&);
void testMult(istream&, ostream&);
void testPlusEqual(istream&, ostream&);
void testDerivative(istream&, ostream&);


int getChoice();

int main(){
	ifstream input("input.txt");
	ifstream reset("reset.txt");
	ifstream eval("eval.txt");
	ifstream add("add.txt");
	ifstream mult("mult.txt");
	ifstream plusE("pluse.txt");
	ifstream deriv("deriv.txt");

	int choice = getChoice();
	while(choice){
		system("cls");
		switch (choice){

			case 1: testConstructor(cout);break;
			case 2: testInput(input,cout); break;
			case 3: cout << "Tested in other methods" ; break;
            case 4: testReset(reset,cout); break;
			case 5: testEvaluate(eval,cout); break;
			case 6: testAdd(add,cout); break;
			case 7: testMult(mult,cout); break;
			case 8: testPlusEqual(plusE,cout); break;
			case 9: testDerivative(deriv,cout); break;
			default: cout << "invalid selection" << endl;
		}
		cout << "Press Enter to Continue" << endl;
		cin.get();cin.get();
		system("cls");
		choice = getChoice();
	}

	return 0;
}

void testConstructor(ostream&os){
	os<< "TESTING CONSTRUCTOR" << endl;
	os<< "EXPECT:\t" << "<>" << endl;
	Poly p;
	os << "ACTUAL:\t" << p << endl;
}

void testInput(istream& is, ostream&os){
	os << "TESTING EXTRACTION OPERATOR" << endl;
	os << "Enter Polynomial in specified format" << endl;
	Poly p;
	is >> p; os<< endl;
	os<< "ACTUAL:\t" << p << endl;
}

void testReset(istream& is, ostream&os){
	os<< "TESTING RESET, MUST HAVE INPUT" << endl;
	os<< "Enter a Polynomial" << endl;
	Poly p;
	is >> p;
	os<< "BEFORE RESET:\t" << p << endl;
	p.Reset();
	os<< "AFTER RESET:\t" << p << endl;
}

void testEvaluate(istream& is, ostream&os){
	os<< "TESTING EVALUATE" << endl;
	os << "Enter a Polynomial" << endl;
	Poly p;
	is >> p;
	os<< "Enter the value for x" << endl;
	int x;
	is>> x;
	os<< "Polynomial:\t" << p << endl;
	os<< "evaluated at\t" << x << endl;
	os<< "is \t " << p.Eval(x) << endl;
}
void testAdd(istream& is, ostream&os){
	os<< "TESTING ADD" << endl;
	Poly p1, p2;
	os<< "Enter Left Operand" << endl;
	is>> p1;
	os<< "Enter Right Operand " << endl;
	is>> p2;
	os<< p1 << " + " << p2 << "=" << endl;
	os<< p1 + p2 << endl;

}
void testMult(istream& is, ostream&os){
	os<< "TESTING MULTIPLY" << endl;
	Poly p1, p2;
	os<< "Enter Left Operand" << endl;
	is>> p1;
	os<< "Enter Right Operand " << endl;
	is>> p2;
	os<< p1 << " * " << p2 << "=" << endl;
	os<< p1 * p2 << endl;
}
void testPlusEqual(istream& is, ostream&os){
	os<< "TESTING PLUS EQUAL" << endl;
	Poly p1, p2;
	os<< "Enter Left Operand" << endl;
	is>> p1;
	os<< "Enter Right Operand " << endl;
	is>> p2;
	os<< p1 << " += " << p2 << "=" << endl;
	p1+=p2;
	os<< p1 << endl;
}
void testDerivative(istream& is, ostream&os){
	os<< "TESTING DERIVATIVE" << endl;
	Poly p1;
	os<< "Enter Polynomial" << endl;
	is>> p1;
	os<< "The Derivative of " << p1 << "is" << endl;
	p1.Derivative();
	os<< p1 << endl;
}


int getChoice(){
	cout << "Select one" << endl;
	cout << "1. Test Constructor" << endl;
	cout << "2. Test Input " << endl;
	cout << "3. Test Output" << endl;
	cout << "4. Test Reset " << endl;
	cout << "5. Test Evaluate " << endl;
	cout << "6. TestAdd" << endl;
	cout << "7. TestMult" << endl;
	cout << "8. TestPlusEqual" << endl;
    cout << "9. TestDerivative" << endl;
	cout << "0. Quit" << endl;
	int c;
	cin >> c;
	return c;
}
