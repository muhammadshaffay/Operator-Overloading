class Polynomial
{
	public:
		int *polyarray;
		int size;

	public:
		Polynomial();
		Polynomial(int);
		Polynomial(const Polynomial &);
		Polynomial& operator=(const Polynomial &);
		bool operator==(const Polynomial &);
		Polynomial operator+(const Polynomial &);
		Polynomial operator-(const Polynomial &);
		Polynomial operator*(const Polynomial &);
		void operator+=(const Polynomial&);
		void operator-=(const Polynomial&);
		~Polynomial();

	void setsize(int s);
	int getsize();
	void setvalue(int i , int v);
	int getvalue(int i);
	//operator string();
};
