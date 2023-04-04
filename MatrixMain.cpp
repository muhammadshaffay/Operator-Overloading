#include"Matrix.h"

int main(int argc, char **argv) {

	//parametrized constructor
		Matrix M1(5 , 5);
		cin>>M1;
		cout<<M1;
	//default constructor
		Matrix M2;
	//input stream
		cin>>M2;
		cout<<M2;
	//copy constructor
		Matrix M3(M2);
	//output stream
		cout<<M3;
	//set value at i , j
		M3(1 , 1 , 1.2);
	//assigning a matrix returning same
		Matrix M4 = (M3);
		cout<<M4;
	//compares two matrices
		bool f = M2==M3;
		cout<<f;
	//adds two matrics and returns the result
		Matrix M5(M3 + M4);
		cout<<M5;
	//subtracts two matrics and returns the result
		Matrix M6(M3 - M4);
		cout<<M6;
	//multiplies two matrics and returns the result
		Matrix M7(M4 * M3);
		cout<<M7;
	//increments the object
		M3++;
	//adds two matrices
		M3 += M4;
	//subtracts two matrices
		M3 -= M4;

	return 0;
}



