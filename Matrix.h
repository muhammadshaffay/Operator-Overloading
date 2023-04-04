class Matrix
{
	public:
		int columns;
		int rows;

	public:
		float **mat;
		Matrix();
		Matrix(int, int);
		Matrix(const Matrix &);
		void operator()(int i, int j, float val);
		Matrix& operator=(const Matrix &);
		bool operator==(const Matrix &);
		Matrix operator+(const Matrix &);
		Matrix operator-(const Matrix &);
		Matrix operator*(const Matrix &);
		Matrix& operator++(int);
		void operator+=(const Matrix&);
		void operator-=(const Matrix&);
		~Matrix();

		int getrows();
		int getcolumns();
		float getvalues(int , int);
		void setrows(int);
		void setcolumns(int);
		void setvalues(int , int , float);
		operator string();

};
