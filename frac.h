// Instructor: Rafael Arce Nazario
// Curso: CCOM-3034
// Laboratorio #1
// Estudiantes: Daniel Ramirez & Ramon Collazo

#ifndef FRAC_H
#define FRAC_H

class Fraction {
private:
    	int num, denom; //Private variables thats saves numerator and denominator
public:
	Fraction();
    	Fraction(int n, int d);
    	//Mutators and Accesors
    	void setNum(int n);   //It assigns the parameter to the
			      // numerator of a Fraction
    	void setDenom(int d); //It assigns the parameter to the
			      // numerator of a Fraction

    	int  getNum(); //It returns the numerator of the Fraction
    	int  getDenom(); //It returns the denominator of the Fraction

	//Protype functions
	//It prints the Fraction in the form num"/"denom
    	void print(); 
	
	//It returns the calling variable plus the parameter
	Fraction add(const Fraction & F);

	//It returns the calling variable minus the parameter
	Fraction sub(const Fraction & F);
	
	//It returns the calling variable times the parameter
    	Fraction mul(const Fraction & F); 

	//It returns the calling variable divided by the parameter
	Fraction div(const Fraction & F); 

	//It returns true if the calling variable is
	// greater or equal than the parameter	
    	bool gt(const Fraction & F);

	//It simplifies the calling Fraction
    	Fraction reduce(); 
};
#endif
