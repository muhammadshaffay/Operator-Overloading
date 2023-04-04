#include"Array.h"
#include<iostream>
#include<cstring>
using namespace std;

istream& operator>>(istream& input, Array ar)//input stream
	{
		int lengthh = 0;
		int num = 0;

		cout<<"Enter Length Of Array : ";
		input>>lengthh;

		ar.setlength(lengthh);

		for(int x = 0; x < lengthh; x++)
		{
			cout<<"Enter Value At Index ( "<<x + 1<<" ) : ";
			input>>num;
			ar.setvalue(x , num);
		}
		return input;
	}

	ostream& operator<<(ostream& ouput, Array ar)//output stream
	{
		int size = ar.getlength();

		for(int x = 0; x < size; x++)
		{
			ouput<<"Your Value is : "<<ar.getvalue(x)<<endl;
		}
		return ouput;
	}

	void Array::setlength(int l)//seting length
	{
		this->len = l;
	}

	void Array::setvalue(int in , int va)//setting array values
	{
		this->arry[in] = va;
	}

	int Array::getlength()//getting length
	{
		return this->len;
	}

	int Array::getvalue(int in)//getting values
	{
		return this->arry[in];
	}

	Array::Array()//default constructor
	{
		len = 0;
		this->arry = new int[len];
	}

	Array::Array(int size)//parametrized constructor
	{
		this->arry = new int[size];
		this->len = size;
	}

	Array::Array(int *arr, int size)//parametrized constructor
	{
		this->arry = new int[size];
		this->len = size;

		for(int x = 0; x < size; x++)
		{
			this->arry[x] = arr[x];
		}
	}

	Array::Array(const Array &arr)//copy constructor
	{
		this->len = arr.len;
		this->arry = new int[arr.len];

		for(int x = 0; x < arr.len; x++)
		{
			this->arry[x] = arr.arry[x];
		}
	}

	int Array::operator[](int i)//index-value returner
	{
		if(i > this->len)
		{
			return 9999;
		}

		return this->arry[i];
	}

	void Array::operator=(const Array arr)//copies one array to other
	{
		this->len = arr.len;
		this->arry = new int [arr.len];

		for(int x = 0; x < arr.len; x++)
		{
			this->arry[x] = arr.arry[x];
		}
	}

	Array Array::operator+(const Array arr)//adds two arrays
	{
		Array temp;

		if(this->len > arr.len)
		{
			temp.len = this->len;
		}
		else if(this->len < arr.len)
		{
			temp.len = arr.len;
		}
		else if(this->len == arr.len)
		{
			temp.len = this->len;
		}

		temp.arry = new int[temp.len];

		if(this->len > arr.len)
		{
			for(int x = 0; x < this->len; x++)
			{
				temp.arry[x] = this->arry[x];
			}
			for(int x = 0; x < arr.len; x++)
			{
				temp.arry[x] += arr.arry[x];
			}
		}
		else if(this->len < arr.len)
		{
			for(int x = 0; x < arr.len; x++)
			{
				temp.arry[x] = arr.arry[x];
			}
			for(int x = 0; x < this->len; x++)
			{
				temp.arry[x] += this->arry[x];
			}
		}
		else if(this->len == arr.len)
		{
			for(int x = 0; x < this->len; x++)
			{
				temp.arry[x] = this->arry[x];
			}
			for(int x = 0; x < arr.len; x++)
			{
				temp.arry[x] += arr.arry[x];
			}
		}
		return temp;
	}

	Array Array::operator-(const Array arr)//subtracts two arrays
	{
		Array temp;

		if(this->len > arr.len)
		{
			temp.len = this->len;
		}
		else if(this->len < arr.len)
		{
			temp.len = arr.len;
		}
		else if(this->len == arr.len)
		{
			temp.len = this->len;
		}

		temp.arry = new int[temp.len];

		if(this->len > arr.len)
		{
			for(int x = 0; x < this->len; x++)
			{
				temp.arry[x] = this->arry[x];
			}
			for(int x = 0; x < arr.len; x++)
			{
				temp.arry[x] -= arr.arry[x];
			}
		}
		else if(this->len < arr.len)
		{
			for(int x = 0; x < arr.len; x++)
			{
				temp.arry[x] = arr.arry[x];
			}
			for(int x = 0; x < this->len; x++)
			{
				temp.arry[x] -= this->arry[x];
			}
		}
		else if(this->len == arr.len)
		{
			for(int x = 0; x < this->len; x++)
			{
				temp.arry[x] = this->arry[x];
			}
			for(int x = 0; x < arr.len; x++)
			{
				temp.arry[x] -= arr.arry[x];
			}
		}
		return temp;
	}

	void Array::operator++()//increments each element by one
	{
		for(int x = 0; x < this->len; x++)
		{
			this->arry[x] += 1;
		}
	}

	Array& Array::operator--(int)//decrements each element by one
	{
		for(int x = 0; x < this->len; x++)
		{
			this->arry[x] -= 1;
		}
		return *this;
	}

	bool Array::operator==(const Array arr)//compares two arrays
	{
		if(this->len != arr.len)
		{
			return false;
		}
		int counter = 0;
		for(int x = 0; x < this->len; x++)
		{
			if(this->arry[x] == arr.arry[x])
			{
				counter++;
			}
		}
		if(counter == this->len)
		return true;
		else
		return false;
	}

	bool Array::operator!()//if no element in array
	{
		if (this->len == 0)
		return true;

		else
		return false;
	}

	void Array::operator+=(const Array& arr)//adds two array
	{
		if(this->len == arr.len)
		{
			for(int x = 0; x < this->len; x++)
			{
				this->arry[x] += arr.arry[x];
			}
		}
		else if(this->len > arr.len)
		{
			for(int x = 0; x < arr.len; x++)
			{
				this->arry[x] += arr.arry[x];
			}
		}
		else if(this->len < arr.len)
		{
			for(int x = 0; x < this->len; x++)
			{
				this->arry[x] += arr.arry[x];
			}
		}
	}

	void Array::operator-=(const Array& arr)//subtracts two array
	{
		if(this->len == arr.len)
		{
			for(int x = 0; x < this->len; x++)
			{
				this->arry[x] -= arr.arry[x];
			}
		}
		else if(this->len > arr.len)
		{
			for(int x = 0; x < arr.len; x++)
			{
				this->arry[x] -= arr.arry[x];
			}
		}
		else if(this->len < arr.len)
		{
			for(int x = 0; x < this->len; x++)
			{
				this->arry[x] -= arr.arry[x];
			}
		}
	}

	int Array::operator()(int idx, int val)//returns value at an index
	{
		if(this->arry[idx] != val)
		return -1;

		int counter = 0;

		int *temp = new int[this->len];

		for(int x = 0; x < this->len; x++)
		{
			temp[x] = this->arry[x];
		}
		this->len = this->len - 1;
		arry = new int [this->len];

		for(int x = 0; x < this->len + 1; x++)
		{
			if(x != idx)
			{
				this->arry[counter] = temp[x];
				counter++;
			}
		}
		return 1;
	}

	Array::~Array()//destructor
	{
		cout<<"Array Deleted"<<endl;
		//delete[] arry;
	}
