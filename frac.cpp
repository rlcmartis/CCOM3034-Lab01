// Instructor: Rafael Arce Nazario
// Curso: CCOM-3034
// Laboratorio #1
// Estudiantes: Daniel Ramirez & Ramon Collazo

#include "frac.h"
#include <iostream>
using namespace std;

//Constructor of Fraction assigns default values to num and denom
Fraction::Fraction(){
	num = 0;
	denom = 1;
}

//Another constructor but giving the values given by parameters
Fraction::Fraction(int n, int d){
	num = n;
	denom = d;
}

//Set the numerator equal to parameter n
void Fraction::setNum(int n){
	num = n;
}

//If the parameter d is not zero, the function set the
//denominator equal to d. If it is, print the error and end the function.
void Fraction::setDenom(int d){
	if (d == 0){
	        cout << "ERROR! Division entre cero no esta definido.";
        return;
	}
	else
	denom = d;
}

//Its a function to get the numerator by "return".
int Fraction::getNum(){
	return num;
}

//Its a function to get the denominator by "return".
int Fraction::getDenom(){
	return denom;
}

//If the calling function has num = a and denom = b it prints "a/b"
void Fraction::print(){
	//If the denom is 1, then it is an integer, and prints the numerator
	if (denom == 1)
                cout << num;
	
	//If the num and denom are different, it prints the fraction
	else if (num != denom)
		cout << num << "/" << denom;

	//If the num and denom are the same, it is one, so it prints 1
	else if (num == denom)
	cout << 1;
}

//It sums and return the calling fraction plus the given by parameter
Fraction Fraction::add(const Fraction & F){
	Fraction F1;

	//If the denominators are equal, then just sum the numerators
	if (F.denom == denom){
		F1.num = (F.num + num);
		F1.denom = (denom);
	}
	//If denominators are not equal, sum the crossed multiplications
	//assign them to the numerator and multiply the denominators
	else{
		F1.num = ((F.num * denom) + (F.denom * num));
		F1.denom = (F.denom * denom);
	}
	//Reduce the fraction before returning it
	F1=F1.reduce();
	return F1;
}

//It substracts and return the calling fraction minus the given by parameter
Fraction Fraction::sub(const Fraction & F){
	Fraction F1;
	//If the denominators are 
	if (F.denom == denom){
        	F1.num = (num - F.num);
        	F1.denom = (denom);
	}
	else{
        	F1.num = ((F.denom * num) - (F.num * denom));
            	F1.denom = (F.denom * denom);
    	}

    	//Reduces the fraction before returning it
	F1=F1.reduce();
    	return F1;
}

//Multiplies the fractions with the parameter's fractions
Fraction Fraction::mul(const Fraction & F){
	Fraction F1;
	F1.num = num * F.num;
	F1.denom = denom * F.denom;

	//Educes the fraction before returning it
	F1= F1.reduce();
	return F1;
}

//Divisdes the fractions with the parameter's fractions
Fraction Fraction::div(const Fraction & F){
	Fraction F1;
	F1.num = num * F.denom;
	F1.denom = denom * F.num;

	//Reduces the fraction before returning it
	F1 = F1.reduce();
	return F1;
}

//Returns true if the parameter is smaller then the fraction it is compared to
bool Fraction::gt(const Fraction & F){
	if((num*F.denom) >= (F.num*denom))
		return true;
	return false;
}

Fraction  Fraction::reduce(){
	Fraction F; //Fraction to be returned
	//Equals the variables numbers
	F.num = num;
	F.denom= denom;
	//If the num is greater than the denom ...
	if (num >= denom){
		//...It will divide by i = num if it both the num and denom
		//are divisible by i, untill i is 1.
		for (int i= num; i > 1; i--){
			if ((F.num % i== 0) && (F.denom % i==0)){
				F.num = F.num /i;
				F.denom= F.denom /i;
			}
		}
	}
	//If the denom is greater than the num ...
	else {
		//...It will divide by i = denom if it both the num and denom
                //are divisible by i, untill i is 1.
		for (int i= denom; i > 1; i--){
                        if ((F.num % i== 0) && (F.denom % i==0)){
                                F.num = F.num /i;
                                F.denom= F.denom /i;
                        }
                }
	}
	return F;
}
