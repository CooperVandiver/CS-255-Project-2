//******************************************************
// Name: Cooper Vandiver
// File: Poly.cpp
// Description: Implementation of the specified functions listed in Poly.h. These functions include
//              a constructor, an evaluate function, a reset function, a derivative function, as well
//              as overloading of the extraction, insertion, addition, multiplication, and addition
//              assignment operators.
// Course: CS 255
// Due Date: Oct. 28, 2021
//******************************************************
#include <iostream>
#include <cmath>
#include "Poly.h"
using namespace std;

//******************************************************
// Function Name: Poly()
// Brief Description: Initializes the integer array "terms[]" in a newly created polynomial
// Return Value: N/A
// Incoming Parameters: N/A
// Outgoing Parameters: N/A
//******************************************************
Poly::Poly(){
    for(int i = 0; i<MAX; i++){ //setting loop to run for all elements of terms.
        terms[i] = 0;           //setting each element's value to 0.
    }
}

//******************************************************
// Function Name: double Eval(double x)
// Brief Description: Evaluates a polynomial at a specified value of x
// Return Value: A double value equal to the result of the polynomial evaluated at x
// Incoming Parameters: One double value
// Outgoing Parameters: N/A
//******************************************************
double Poly::Eval(double x){
    double sum;                     //declaring variables.
    double num;
    for(int i = 0; i<MAX; i++){     //loop to run for all elements of terms.
        num = 1;                    //setting num to 1 for multiplication.
        for(int j = 0; j<i; j++){   //loop to run i times.
            num = num * x;          //multiplying x by itself i times.
        }
        sum += terms[i] * num;      //adding product of x^i * value of terms[i] to running sum.
    }
    return sum;                     //returning value of polynomial evaluated at x.
}

//******************************************************
// Function Name: void Reset()
// Brief Description: Resets the values in calling object's integer array "terms[i]" to 0
// Return Value: N/A
// Incoming Parameters: N/A
// Outgoing Parameters: N/A
//******************************************************
void Poly::Reset(){
    for(int i = 0; i<MAX; i++){     //loop to run for all elements of terms.
        terms[i] = 0;               //setting all elements of terms back to 0.
    }
}

//******************************************************
// Function Name: void operator+=(const Poly& p)
// Brief Description: Overloads the addition assignment operator, setting the calling object equal to itself being added with the Polynomial p
// Return Value: N/A
// Incoming Parameters: One polynomial passed by reference (specified as a constant)
// Outgoing Parameters: The unchanged polynomial passed by reference
//******************************************************
void Poly::operator+=(const Poly& p){
    *this = *this + p;              //adding polynomial p to calling object.
}

//******************************************************
// Function Name: void Derivative()
// Brief Description: Calculates the derivative of a polynomial
// Return Value: N/A
// Incoming Parameters: N/A
// Outgoing Parameters: N/A
//******************************************************
void Poly::Derivative(){
    for(int i = 1; i<MAX; i++){     //loop to run for all elements of terms.
        terms[i-1] = terms[i] * i;  //using the power rule to calculate the derivative of the function.
    }                               //the constant is being taken care of by being overridden by the derivative
}                                   //of terms[i] (whether it actually has a value or is 0).

//******************************************************
// Function Name: istream& operator>>(istream& is, Poly& p)
// Brief Description: Overloads the extraction operator to input values into the polynomial
// Return Value: The istream variable
// Incoming Parameters: An istream variable and a polynomial, both passed by reference
// Outgoing Parameters: The istream variable and the polynomial
//******************************************************
istream& operator>>(istream& is, Poly& p){
    int num;                                //declaring variables.
    int exp;
    char dummy;
    is>>dummy;                              //inputting the first '<'.
    while(dummy != '>'){                    //while loop to run while character inputted isn't '>'.
        is>>num>>dummy>>dummy>>exp>>dummy;  //inputting the term and exponent while ignoring characters.
        if(p.terms[exp] == 0){              //case for specified element of terms being empty.
            p.terms[exp] = num;             //setting value of terms[exp] to num if true.
        }
        else{                               //if element is not empty.
            p.terms[exp] += num;            //adding inputted value to current value if true.
        }
    }
    return is;

}

//******************************************************
// Function Name: ostream& operator<<(ostream& os, const Poly& p)
// Brief Description: Overloads the insertion operator to output the values of the polynomial
// Return Value: An ostream variable
// Incoming Parameters: An ostream variable and a polynomial, both passed by reference, with the polynomial set as a constant
// Outgoing Parameters: The ostream variable as well as the unchanged polynomial
//******************************************************
ostream& operator<<(ostream& os, const Poly& p){
    os<<'<';                                    //outputting initial '<'.
    for(int i = MAX-1; i>=0; i--){              //loop to run for all elements of terms in reverse order.
        if(p.terms[i] != 0){                    //case for terms[i] not being empty.
            if(i == 1){                         //case for i, and thus the exponent, being 1.
                if(p.terms[i] == 1){            //if the value of terms[i] is 1, the 1 is not outputted due to being implied.
                    os<<'x';                    //outputting x.
                }
                else{                           //case for terms[i] being >1 or <1.
                    os<<p.terms[i]<<'x';        //outputting value of terms[i] as well as x.
                }
            }
            else if(i == 0){                    //case for i being 0, or the term being a constant.
                os<<p.terms[i];                 //outputting value of the constant.
            }
            else{                               //case for i being >1.
                if(p.terms[i] == 1){            //case for terms[i] being equal to 1.
                    os<<"x^"<<i;                //only outputting the x^i due to the 1 being implied.
                }
                else{                           //case for i being >1 or <0.
                    os<<p.terms[i]<<"x^"<<i;    //outputting value of terms[i] * x ^ i.
                }
            }
            for(int j = i-1; j>=0; j--){        //loop to run for all elements of terms that are less than i.
                if(p.terms[j] != 0){            //case for a value assigned to terms after terms[i] not being empty.
                    os<<'+';                    //outputting a '+' due to another value being present in the array.
                    j = -1;                     //setting j to -1 to exit loop.
                }
            }
        }
    }
    os<<'>';                                    //outputting the ending '>' character.
    return os;                                  //returning the output stream.
}

//******************************************************
// Function Name: Poly operator+(Fraction& left, Fraction& right)
// Brief Description: Overloads the addition operator to add two polynomials together
// Return Value: A polynomial
// Incoming Parameters: Two polynomials passed by reference and set to be constant
// Outgoing Parameters: The two unchanged polynomials
//******************************************************
Poly operator+(const Poly& p1, const Poly& p2){
    Poly temp;                                      //declaring a temporary polynomial.
    for(int i = MAX-1; i>=0; i--){                  //loop to run for all elements of terms.
        temp.terms[i] = p1.terms[i] + p2.terms[i];  //adding p1's and p2's values of the current element of i to temp.terms[i].
    }
    return temp;                                    //returning temp.
}

//******************************************************
// Function Name: Poly operator*(const Poly& p1, const Poly& p2))
// Brief Description: Overloads the multiplication operator to multiply to polynomials together. Uses exponent multiplication rules
//                    to determine which element to place multiplied values of the elements of p1.terms and p2.terms in.
// Return Value: N/A
// Incoming Parameters: Two fractions passed by reference (left and right)
// Outgoing Parameters: Two fractions passed by reference (left and right)
//******************************************************
Poly operator*(const Poly& p1, const Poly& p2){
    Poly temp;                                                      //declaring a temporary polynomial.
    for(int i = 0; i<MAX; i++){                                     //loop to run for all elements of p1.terms.
        if(p1.terms[i] != 0){                                       //case for p1.terms[i] not being empty.
            for(int j = 0; j<MAX; j++){                             //loop to run for all elements of p2.terms.
                if(temp.terms[i+j] != 0){                           //case for element of temp.terms not being empty.
                    temp.terms[i+j] += p1.terms[i] * p2.terms[j];   //adding product of multiplication to current value.
                }
                else{                                               //case for element of temp.terms being empty.
                    temp.terms[i+j] = p1.terms[i] * p2.terms[j];    //setting specified element of temp.terms to product.
                }
            }
        }
    }
    return temp;                                                    //returning temp.
}
