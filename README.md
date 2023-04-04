# Operator-Overloading-Cpp
Repository showcasing overloaded operators for arrays, matrices, strings, and polynomials.

#### STRING
class String{

// think about the private data members...

3   public:

4   // provide definitions of following functions...

5   String();// default constructor
6   String(char *str);// initializes the string with constant cstring
7 String(const String &);// copy constructor to initialize the string fromexisting ,! string

8   String(int x);// initializes a string of pre-defined size

9   char operator[](int i);// returns the character at index [x]

String& operator+(String str );// append a String at the end of string

String& operator-(String substr);//removes the substr from the string

bool operator!();// returns true if string is empty..

String& operator=(const String&);// Copy one string to another ...

bool operator==(const String&);//returns true if two strings are equal

int operator()(char);// returns the index of character being searched.
String operator*(int a);//multiples the string by i times and return the string. ,! Remember the Python functionality for *

int length();// returns the length of string

˜String();// destructor...

};

istream& operator<<(istream& input,const String);//Inputs the string

ostream& operator>>(ostream& ouput,const String); //Outputs the string
