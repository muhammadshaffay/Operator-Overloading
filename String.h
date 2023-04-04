class String
{
	public:
		char *word;
		int lengt;

	public:

		String();
		String(char *str);
		String(const String &);
		String(int x);
		char operator[](int i);
		String& operator+(String str );
		String& operator-(String substr);
		bool operator!();
		String& operator=(const String&);
		bool operator==(const String&);
		int operator()(char);
		String operator*(int a);
		int length();
		~String();

		void setlength(int le);
		void setstring(char *arr);
		int getlength();
		char getstring(int i);

};
