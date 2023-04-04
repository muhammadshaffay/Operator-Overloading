#include"Polynomial.h"

int main(int argc, char **argv) {

	//default constructer
		Polynomial P1;
	//parametrized constructor
		Polynomial P2(5);
		for(int i = 0; i<5; i++)
		{
				P2.polyarray[i] = 2;
		}
	//copy constructor
		Polynomial P3(P2);
	//assigns a polynomial
	//	Polynomial P4 = P2;//not working
		//return true if equal
		bool c = P3 == P2;
		//cout<<c;
	//adding 2 polynomials and returing
		Polynomial P5 = P3 + P2;
		for(int i = 0; i<5; i++)
		{
			cout<<P5.polyarray[i];
		}
		cout<<endl;
	//subtracting 2 polynomials and returing
		Polynomial P6 = P3 - P2;
		for(int i = 0; i<5; i++)
		{
			cout<<P6.polyarray[i];
		}
		cout<<endl;

	return 0;
}




