#include"Array.h"

int main(int argc, char **argv) {

		int a[5] = {1,2,3,4,5};

		//calls parametrized constructor
		Array a1(a , 5);

		//calls function that makes array of size
		Array a2(5);

		//calls copy construcctor
		Array a3(a1);

		//returns value at an index
		cout<<a1[1];

		//coppies one object to another
		Array a4 = a1;

		//add two arrays
		Array a5 = a4 + a1;

		//subtracts two arrays
		Array a6 = a4 - a1;

		//increments an object array
		++a1;

		//decrements an object array
		a1--;

		//adds two stores in caller
		a4 += a1;

		//subtracts two stores in caller
		a1 -= a4;

		//tells true if index told and value ar correct
		a1(1 , 4);

		//cout<<a1;
		//cin>>a1;

	return 0;
}




