#include"Polynomial.h"
#include<iostream>
#include<cstring>
using namespace std;

/*Matrix :: operator string()
        {
	        string word = to_string(size);

	        for(int x=0; x < rows; x++)
            	{

                			word = word + to_string(int(polyarray[x]));

                }
		return word;
		}
*/

void Polynomial::setsize(int s)
	{
		this->size = s;
	}
	void Polynomial::setvalue(int i , int v)
	{
		this->polyarray[i] = v;
	}
	int Polynomial::getsize()
	{
		return this->size;
	}
	int Polynomial::getvalue(int i)
	{
		return this->polyarray[i];
	}

	istream& operator<<(istream& input, Polynomial &py)
	{
		int highest_power = 0;
		int num = 0;

		cout<<"Enter Highest Power Of Polynomial : ";
		input>>highest_power;

		py.setsize(highest_power);

		for(int x = 0; x < highest_power; x++)
		{
			cout<<"Enter Value At Index ( "<<x + 1<<" ) : ";
			input>>num;
			py.setvalue(x , num);
		}
		return input;
	}

	ostream& operator>>(ostream& ouput, Polynomial& py)
	{
		int length = py.getsize();

		for(int x = 0; x < length; x++)
		{
			ouput<<"Your Value is : "<<py.getvalue(x)<<endl;
		}
		return ouput;
	}

	Polynomial::Polynomial()
	{
	//	cout<<"Polynomial Created "<<endl;
		size = 0;
		polyarray = new int[size];
	}

	Polynomial::Polynomial(int a)
	{
	//	cout<<"Polynomial Created of size "<<a<<endl;
		this->size = a;

		this->polyarray = new int[this->size];
	}
	Polynomial::Polynomial(const Polynomial &py)
	{
		this->size = py.size;

	//	cout<<"copy constructor in action"<<endl;
	//	delete[] polyarray;
		this->polyarray = new int[py.size];

		for(int x = 0; x < py.size; x++)
		{
			polyarray[x] = py.polyarray[x];
		}
	}
	Polynomial& Polynomial::operator=(const Polynomial &py)
	{
		this->size = py.size;

	//	cout<<"copier in action"<<endl;
	//	cout<<py.size;

		delete[] polyarray;
		this->polyarray = new int[py.size];

		for(int x = 0; x < py.size; x++)
		{
			polyarray[x] = py.polyarray[x];
		}
		return *this;
	}
	bool Polynomial::operator==(const Polynomial &py)
	{
		int counter = 0;

		if(this->size != py.size)
		{
			return 0;
		}

		for(int x = 0; x < this->size; x++)
		{
			if(this->polyarray[x] == py.polyarray[x])
			{
				counter++;
			}
		}

		if(this->size == counter)
		{
			return 1;
		}
		else
		return 0;
	}

	Polynomial Polynomial::operator+(const Polynomial &py)
	{
		Polynomial temp;
		int counter = 0;

		if(this->size < py.size)
		{
			temp.size = py.size;
			temp.polyarray = new int[py.size];
		}

		else if(this->size > py.size || this->size == py.size)
		{
			temp.size = this->size;
			temp.polyarray = new int[this->size];
		}


		if(this->size < py.size)
		{
			for(int x = 0; x < this->size; x++)
			{
				temp.polyarray[x] = this->polyarray[x] + py.polyarray[x];
				counter++;
			}
			for(int x = counter; x < py.size; x++)
			{
				temp.polyarray[x] =  py.polyarray[x];
			}
		}
		else if(this->size > py.size || this->size == py.size)
		{
			for(int x = 0; x < py.size; x++)
			{
				temp.polyarray[x] = this->polyarray[x] + py.polyarray[x];
				counter++;
			}
			for(int x = counter; x <this->size; x++)
			{
				temp.polyarray[x] =  this->polyarray[x];
			}
		}
		return temp;
	}
	Polynomial Polynomial::operator-(const Polynomial &py)
	{
		Polynomial temp;
		int counter = 0;

		if(this->size < py.size)
		{
			temp.size = py.size;
			temp.polyarray = new int[py.size];
		}

		else if(this->size > py.size || this->size == py.size)
		{
			temp.size = this->size;
			temp.polyarray = new int[this->size];
		}


		if(this->size < py.size)
		{
			for(int x = 0; x < this->size; x++)
			{
				temp.polyarray[x] = this->polyarray[x] - py.polyarray[x];
				counter++;
			}
			for(int x = counter; x < py.size; x++)
			{
				temp.polyarray[x] =  py.polyarray[x];
			}
		}
		else if(this->size > py.size || this->size == py.size)
		{
			for(int x = 0; x < py.size; x++)
			{
				temp.polyarray[x] = this->polyarray[x] - py.polyarray[x];
				counter++;
			}
			for(int x = counter; x <this->size; x++)
			{
				temp.polyarray[x] =  this->polyarray[x];
			}
		}
		return temp;
	}
	Polynomial Polynomial::operator*(const Polynomial &py)
	{
		Polynomial temp;

		temp.size = this->size * py.size - 1;

		temp.polyarray = new int[this->size * py.size - 1] ;

		for(int i = 0; i < temp.size; i++)
		{
			temp.polyarray[i] = 0;
		}

		/*for (int i = 0; i < m; i++)
   		{
     	for (int j = 0; j < n; j++)
     	{
     		prod[i+j] += A[i]*B[j];
		}
   		}

   	return prod;*/
	}
	void Polynomial::operator+=(const Polynomial &py)
	{
		if(this->size > py.size)
		{
			for(int i = 0; i < py.size; i++)
			{
				this->polyarray[i] += py.polyarray[i];
			}
		}
		else if(this->size < py.size)
		{
			for(int i = 0; i < this->size; i++)
			{
				this->polyarray[i] += py.polyarray[i];
			}
		}
	}
	void Polynomial::operator-=(const Polynomial &py)
	{
		if(this->size > py.size)
		{
			for(int i = 0; i < py.size; i++)
			{
				this->polyarray[i] -= py.polyarray[i];
			}
		}
		else if(this->size < py.size)
		{
			for(int i = 0; i < this->size; i++)
			{
				this->polyarray[i] -= py.polyarray[i];
			}
		}
	}
	Polynomial::~Polynomial()
	{
		this->size = 0;
		cout<<"Polynomial destroyed"<<endl;
	}
