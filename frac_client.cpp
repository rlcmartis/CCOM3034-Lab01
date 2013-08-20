// Instructor: Rafael Arce Nazario
// Curso: CCOM-3034
// Laboratorio #1
// Estudiantes: Ramon Collazo & Daniel Ramirez

#include <iostream>
#include <algorithm>
#include <time.h>
#include "frac.h"
using namespace std;

//Global variable
const int NSIZE = 10;

//Prototype functions
Fraction sumatory(Fraction []);
void sort(Fraction []);
void printarray(Fraction []);
void options(int &, Fraction &, Fraction &);
void info(int, Fraction [], Fraction &, Fraction &, Fraction &);

//Begins main function
int main(){
    	//Declaration of variables and objects
	Fraction nums[NSIZE]; //Array of Fraction type objects
	Fraction suma, a, b;  //The frac to store the sumatory and two
                          //Frac objects used for sum, substract, etc.
	int opcion;           //Holds option
	char son;             //Used to store the answer to continue or to stop
	bool continuar = false; //Used to repeat or quit the program
	
	//Displays message
	system("clear");
	cout << "Creando lista de fracciones aleatorias...\n";
	srand(time(NULL)); //Used to reset the seed of random numbers.
    	for (int i = 0; i < NSIZE; i++){
        	//Asigns a random number between 1 and 9 to the num and denom
        	nums[i].setNum(rand() % 9 + 1);
        	nums[i].setDenom(rand() % 9 + 1);
	}

	cout << "Lista de fracciones creada.";
	cout << endl;

	do{
	        //If the user wants to continue, clears screen
	        if(continuar == true){
           		system("clear");
			cout << "OJO: " << endl;    
			cout << "\tSe esta usando la misma lista de numeros "
			     << "aleatorios. " << endl;
        	}
        	
		//This function sends an option, the Frac array,
		//and two Frac Objects
        	options(opcion, a, b);
	        
		//The information is processed in this function
	        info(opcion, nums, a, b, suma);

	        //Asks user to continue or to quit
	        cout << endl << "Desea continuar? [S/N]: ";
	        cin >> son;
        	//Input validation
	        while (son !='S' && son !='s' && son !='N' && son !='n'){
                	cout << "Escriba 's' para si o 'n' para no: ";
                	cin >> son;
	        }
	        cout << endl;

        	if (son == 'N' || son == 'n')
			continuar = false; //Stops the program
        	else
			continuar = true;  //Continues the program
	} while(continuar);

	cout << "\nCerrando...\n";

	return 0;
}

void options(int &opcion, Fraction & a, Fraction & b){
	int tempa, tempb; //Used to store first fraction
	int tempx,tempy; //Used to store second fraction

	//Ask user for an option
	cout << "\nQue desea hacer a continuacion?"
		<< "\n\t1) Sumar \n\t2) Restar"
		<< "\n\t3) Multiplicar \n\t4) Dividir"
		<< "\n\t5) Comparar \n\t6) Ordenar lista"
		<< "\n\t7) Calcular sumatoria"
		<< endl << "Usted escogio la opcion: ";
        cin >> opcion; //Stores the option

        //Input validation
        while (opcion < 1 || opcion > 7){
		cout << "Error! Seleccione una opcion correcta: ";
		cin >> opcion;
        }

        //If the option requires two values, asks for which two of them
        if (opcion < 6){
		cout << "Someta los siguientes datos para las "
		     << "fraciones." << endl;

		cout << "Fraccion 1, numerador: ";
		cin >> tempa;
		cout << "Fraccion 1, denominador: ";
		cin >> tempb;
		//Input validation
		while (tempb == 0){
			cout << "El denominador no puede ser 0: ";
			cin >> tempb;
		}
		cout << "Fraccion 2, numerador: ";
		cin >> tempx;
		cout << "Fraccion 2, denominador: ";
		cin >> tempy;
		//Input validation
		while (tempy == 0){
                        cout << "El denominador no puede ser 0";
                        cin >> tempy;
                }

		//Sets the values
		a.setNum(tempa);
		a.setDenom(tempb);
		b.setNum(tempx);
		b.setDenom(tempy);

        }
        cout << "\n\t---> ";
}

void info(int opcion, Fraction nums[], Fraction & a,
	  Fraction & b, Fraction & suma){

	switch(opcion){
        	//This case displays the sum of the two chosen fractions
        	case 1: a.reduce().print();
                	cout << " + ";
                	b.reduce().print();
                	cout << " = ";
                	a.add(b).print();
                	break;

            	//This case displays the subtraction of the two chosen fractions
            	case 2: a.reduce().print();
                        cout << " - ";
                        b.reduce().print();
                        cout << " = ";
                        a.sub(b).print();
                        break;

		//This case displays the mult of the two chosen fractions
		case 3: a.reduce().print();
                	cout << " x ";
                	b.reduce().print();
                	cout << " = ";
                        a.mul(b).print();
                        break;

		//This case displays the d ivision of the two chosen fractions
		case 4: cout << '(';
                	a.reduce().print();
                    	cout << ") / (";
                   	b.reduce().print();
                    	cout << ") = ";
                    	a.div(b).print();
                    	break;
            	//This case displays which fraction is greater than the other
            	case 5: a.reduce().print();
                    	if(a.gt(b)) //If true, shows a is greater or equal to b
                        	cout << " >= ";
                   	else        //If false, shows that b is greater than a
                        	cout << " < ";
                    	b.reduce().print();
                    	break;

            	//This case displays the sorted array of random fractions
            	case 6: sort(nums);
                	printarray(nums);
                	break;

            	//This case displays the sumatory of the array of fractions
            	case 7: suma = sumatory(nums);
                	cout << "La suma de las fracciones es igual a: ";
                	suma.print();
                	break;

            	//Displays error message
            	default: cout << "Error inesperado en la seleccion...";
	}
}

//This function adds all the fractions in the array
Fraction sumatory(Fraction nums[]){
	Fraction F;  //Temp Fraction used to return values
	//Sets default values to the fraction
	F.setNum(0);
	F.setDenom(1);

	//Adds the temp fraction with the fraction in each position
	for (int i = 0; i < NSIZE; i++)
		F = F.add(nums[i]);

	F = F.reduce();    //Reduces the fraction

	return F;          //Returns the fraction
}

//Implemented sorting function
void sort(Fraction nums[]){

	// Steps through each element of the array
	for (int stindex = 0; stindex < NSIZE; stindex++){
		// smindex is the index of the smallest element
		// we've encountered so far.
   		int smindex = stindex;
		
   		//cindex is the current position
		for (int cindex = stindex + 1;cindex < NSIZE; cindex++){
                //If the current post frac is not greater than the smallest
                //frac, the smallest frac, is the current post frac
       			if (!(nums[cindex].gt(nums[smindex])))
             		smindex = cindex;
    		}

    	// Swap our start frac with the smallest frac
    	swap(nums[stindex], nums[smindex]);
	}
}

//Prints the array recieved
void printarray(Fraction A[]){
	cout << '[';
	for (int i=0; i < NSIZE; i++){
		A[i].print();
		if ((i+1)!=(NSIZE)) //If i isn't the last position,
				   //it won't display the ","
			cout << ", ";
	}
	cout << ']';
}
