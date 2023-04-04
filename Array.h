class Array{

	private:
	int *arry;
	int len;

	public:

	Array();
	Array(int size);
	Array(int *arr, int size);
	Array(const Array &);
	int operator[](int i);
	void operator=(const Array);
	Array operator+(const Array);
	Array operator-(const Array);
	void operator++();
	Array& operator--(int);
	bool operator==(const Array);
	bool operator!();
	void operator+=(const Array&);
	void operator-=(const Array&);
	int operator()(int idx, int val);
	~Array();

	void setlength(int l);
	void setvalue(int in , int va);
	int getlength();
	int getvalue(int in);
};
