#include"String.h"

int main(int argc, char **argv) {

char str[] = "Hello";
//parametrized constructor
	String s1(str);
//input stream	
	cin>>s1;
//output stream
	cout<<"parametrized constructor"<<endl;
	cout<<s1;
//copy constructor
	String s2(s1);
	cout<<" constructor"<<endl;
	cout<<s2;
//making char array of size
	String s3(4);
//returning character at index
	char a = s2[2];
	cout<<"returning character at index 2 : "<<a;
//appending string
	cout<<endl;	
	cout<<"Adding two arrays"<<endl;
	cout<<s1 + s2;
//subtracting string
	cout<<"Subtracting two strings"<<endl;
	cout<<s1 - s2;
//if string is empty
	cout<<!s1<<endl;
//copy one string to other
	s1 = s2;
	cout<<s1;
//iff two strings are equal
	bool f = s1==s2;
	cout<<f<<endl;
//returning length of string
	int l = s1.length();
	cout<<l<<endl;
//returning index of character being searched
	int s = s1('s');
	cout<<s<<endl;  
//multiplies the string by i times
	s1 = s2*(3);
	cout<<s1;


	return 0;
}