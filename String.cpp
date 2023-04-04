#include"String.h"
#include<iostream>
#include<cstring>
using namespace std;

void String::setlength(int le)
		{
			this->lengt = le;
		}

		void String::setstring(char *arr)
		{
			int counter = 0;

			for(int i = 0; arr[i] != '\0'; i++)
			{
				counter++;
			}

			this->lengt = counter;

			this->word = new char[counter];

			for(int i = 0; i < this->lengt; i++)
			{
				this->word[i]  = arr[i];
			}
		}

		int String::getlength()
		{
			return this->lengt;
		}

		char String::getstring(int i)
		{
			return this->word[i];
		}

		istream& operator>>(istream& input, String &str)//Inputs the string
{
	int l = 0;

	cout<<"Enter Length Of String : ";
	input>>l;

	char *p = new char[l];

	str.setlength(l);
	cout<<"Enter string : ";

	input>>p;
	str.setstring(p);

	return input;
}
		ostream& operator<<(ostream& ouput, String &str)  //Outputs the string
{
	ouput<<"Your String : ";

	int size = str.getlength();

	for(int x = 0; x < size; x++)
	{
		ouput<<str.word[x];
	}
	cout<<endl;
	return ouput;
}

		String::String()//default constructor
		{
			lengt = 0;
			this->word = new char [lengt];
		}

		String::String(char *str)//parametrized constructor
		{
			lengt = sizeof(str[0]/sizeof(str));
			word = new char[lengt];

			for(int x = 0; str[x] != '\0'; x++)
			{
				word[x] = str[x];
			}
		}

	String::String(const String &str)//copy constructor
		{
			lengt = str.lengt;
			word = new char[lengt];

			for(int x = 0; str.word[x] != '\0'; x++)
			{
				this->word[x] = str.word[x];//called when s2 = s1 etc
			}
		}

		String::String(int x)//initializes a string of predefined size
		{
			lengt = x;
			this->word = new char[lengt];
		}

		char String::operator[](int i)// returns character at index i
		{
			return	word[i];
		}

		String& String::operator+(String str )// append a String at the end of string
		{
			int temp_size = this->lengt + str.lengt;

			String temp(temp_size);

			for(int i = 0; i < this->lengt; i++)
			{
				temp.word[i] = this->word[i];
			}

			for(int i = 0; i < str.lengt; i++)
			{
			 temp.word[this->lengt + i] = str.word[i];
			}

			delete []word;

			this->word = new char[temp_size];

			for(int i = 0; i <  temp_size; i++)
			{
				this->word[i] = temp.word[i];
			}
			this->lengt = temp_size;

			return *this;
		}

	String& String::operator-(String substr )
{

	int a = 0;
	char *semi_word;

	int size1 = substr.lengt;
	semi_word = strstr(word, substr.word);

	if(semi_word)
	{
		int size2 = lengt - size1;

		String stringer(size2);

		int b = semi_word - word;
		while(a < b)
		{
			stringer.word[a] = word[a];
			a++;
		}

		int c = lengt - size1 - b;

		a = b;

		int total = b + c;

		while(a <= total)
		{
			stringer.word[a] = word[ a + size1 ];
			a++;
		}
		word = stringer.word;

		int counter = 0;

		for(int x  = 0; stringer.word[x] != '\0'; x++)
		{
			counter++;
		}
		this->lengt = counter - 1;
	}

	return *this;

}

		 bool String::operator!()// returns true if string is empty
		 {
		 	int counter = 0;

		 	for(int x = 0; this->word[x] != '\0'; x++)
		 	{
		 		counter++;
			}

			if(counter == 0)
			{
				return true;
			}
			else if(counter != 0)
			{
				return false;
			}
		 }

		 String& String::operator=(const String& str)// Copy one string to another
		 {
		 	this->lengt = str.lengt;

			this->word = new char[this->lengt];

			for(int i = 0; i < this->lengt; i++)
			{
				this->word[i] = str.word[i];
			}
			return *this;
		 }

		 bool String::operator==(const String& str)//returns true if two strings are equal
		 {
		 	int temp = 0;

			if(this->lengt != str.lengt)
			{
				return false;
			}

			for(int x = 0; x < this->lengt; x++)
			{
				if(this->word[x] == str.word[x])
				{
					temp++;
				}
			}

			if(temp == this->lengt)
			{
				return true;
			}
			else if(temp != this->lengt)
			{
				return false;
			}
		 }

		 int String::operator()(char character)// returns the index of character being searched.
		 {
		 	for(int x = 0; this->word[x] != '\0'; x++)
		 	{
		 		if(character == this->word[x])
		 		{
		 			return x;
				}
			}
			return 999;
		 }

		 String String::operator*(int a)//multiples the string by i times
		 {
		 	int temp_size = this->lengt * a;

			String temp(temp_size);

			temp.lengt = temp_size;
			temp.word = new char[temp_size];

			for(int i = 0; i < a; i++)
			{
				for(int j = 0; j < this->lengt; j++)
				{
					temp.word[i * this->lengt + j] = this->word[j];
				}
			}
			return temp;
		 }

		  int String::length()// returns the length of string
		  {
		  	return this->lengt;
		  }

		  String::~String()//destructor
		  {
		 // cout<<"String Destroyed"<<endl;
		  }

