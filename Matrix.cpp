#include"Matrix.h"
#include<iostream>
#include<cstring>
using namespace std;

Matrix :: operator string()
        {
	        string word = to_string(rows) + "X" + to_string(columns);

	        for(int x=0; x < rows; x++)
            	{
	               	word = word + "\n";
            		for (int y=0; y < columns; y++)
                		{
                			word = word + to_string(int(mat[x][y]));
                			if (!(y == columns - 1))

            				(word = word + "-");
                		}
                }
		return word;
		}


void Matrix::setcolumns(int c)
	{
		this->columns = c;
	}
void Matrix::setrows(int r)
	{
		this->rows = r;
	}
int Matrix::getcolumns()
	{
		return columns;
	}
int Matrix::getrows()
	{
		return rows;
	}
void Matrix::setvalues(int r , int c , float va)
	{
		this->mat[r][c] = va;
	}
float Matrix::getvalues(int r , int c)
	{
		return this->mat[r][c];
	}

Matrix::Matrix()
	{
		columns = 0;
		rows = 0;

		this->mat = new float*[rows];

		for(int i = 0; i < rows; i++)
		{
			mat[i] = new float[columns];
		}
	}

Matrix::Matrix(int c, int r)
	{
		this->columns = c;
		this->rows = r;

		mat = new float*[r];
		for(int x = 0; x < r; x++)
		{
			mat[x] = new float[c];
		}
	}
Matrix::Matrix(const Matrix & matr)
	{
		this->columns = matr.columns;
		this->rows = matr.rows;

		this->mat = new float*[rows];
		for(int x = 0; x < rows; x++)
		{
			this->mat[x] = new float[columns];
		}

		for(int x = 0; x < matr.rows; x++)
		{
			for(int y = 0; y < matr.columns; y++)
			{
				this->mat[x][y] = matr.mat[x][y];
			}
		}
	}
	void Matrix::operator()(int i, int j, float val)
	{
		this->mat[i][j] = val;
	}
	Matrix& Matrix::operator=(const Matrix & matr)
	{
		for (int i = 0; i < this->rows; i++)
		{
        	delete[] mat[i];
    	}
    	delete[] mat;

    	this->columns = matr.columns;
		this->rows = matr.rows;

		mat = new float*[matr.rows];
		for(int x = 0; x < matr.rows; x++)
		{
			mat[x] = new float[matr.columns];
		}

		for(int x = 0; x < matr.rows; x++)
		{
			for(int y = 0; y < matr.columns; y++)
			{
				this->mat[x][y] = matr.mat[x][y];
			}
		}
		return *this;
	}
	bool Matrix::operator==(const Matrix& matr)
	{
		if(this->rows != matr.rows)
		return false;

		if(this->columns != matr.columns)
		return false;

		int indexer = 0;

		for(int x = 0; x < matr.rows; x++)
		{
			for(int y = 0; y < matr.columns; y++)
			{
				if(this->mat[x][y] = matr.mat[x][y])
				{
					indexer++;
				}
			}
		}

		if(indexer == (this->rows * this->columns))
		return true;

		else
		return false;
	}
	Matrix Matrix::operator+(const Matrix & matr)
	{
		Matrix temp;

		temp.columns = this->columns;
		temp.rows = this->rows;

		temp.mat = new float*[temp.rows];
		for(int x = 0; x < temp.rows; x++)
		{
			temp.mat[x] = new float[temp.columns];
		}

		for(int x = 0; x < temp.rows; x++)
		{
			for(int y = 0; y < temp.columns; y++)
			{
				temp.mat[x][y] = this->mat[x][y] + matr.mat[x][y];
			}
		}
		return temp;
	}
	Matrix Matrix::operator-(const Matrix & matr)
	{
		Matrix temp;

		temp.columns = this->columns;
		temp.rows = this->rows;

		temp.mat = new float*[temp.rows];
		for(int x = 0; x < temp.rows; x++)
		{
			temp.mat[x] = new float[temp.columns];
		}

		for(int x = 0; x < temp.rows; x++)
		{
			for(int y = 0; y < temp.columns; y++)
			{
				temp.mat[x][y] = this->mat[x][y] - matr.mat[x][y];
			}
		}
		return temp;
	}
	Matrix Matrix::operator*(const Matrix & matr)
	{
		Matrix temp;

		temp.columns = this->columns;
		temp.rows = this->rows;

		temp.mat = new float*[temp.rows];
		for(int x = 0; x < temp.rows; x++)
		{
			temp.mat[x] = new float[temp.columns];
		}

		for(int x = 0; x < temp.rows; x++)
		{
			for(int y = 0; y < temp.columns; y++)
			{
				temp.mat[x][y] = this->mat[x][y] * matr.mat[x][y];
			}
		}
		return temp;
	}
	Matrix& Matrix::operator++(int)
	{
		for(int x = 0; x < this->rows; x++)
		{
			for(int y = 0; y < this->columns; y++)
			{
				this->mat[x][y] += 1;
			}
		}
		return *this;
	}
	void Matrix::operator+=(const Matrix& matr)
	{
		for(int x = 0; x < this->rows; x++)
		{
			for(int y = 0; y < this->columns; y++)
			{
				this->mat[x][y] += matr.mat[x][y];
			}
		}
	}
	void Matrix::operator-=(const Matrix& matr)
	{
		for(int x = 0; x < this->rows; x++)
		{
			for(int y = 0; y < this->columns; y++)
			{
				this->mat[x][y] -= matr.mat[x][y];
			}
		}
	}
	Matrix::~Matrix()
	{
	/*	for (int i = 0; i < this->rows; i++)
		{
        	delete[] mat[i];
    	}
    	delete[] mat;*/
    	cout<<"Matrix Destroyed"<<endl;
	}

istream& operator>>(istream& input, Matrix &matri)
	{
		int r = 0;
		int c = 0;
		float num = 0;

		cout<<"Enter rows : ";
		input>>r;

		cout<<"Enter columns : ";
		input>>c;

		matri.setrows(r);
		matri.setcolumns(c);

		matri.mat = new float*[r];
		for(int x = 0; x < r; x++)
		{
			matri.mat[x] = new float[c];
		}

		for(int x = 0; x < r; x++)
		{
			for(int y = 0; y < c; y++)
			{
				cout<<"Enter Value At Index ( "<<x + 1<<" )  ( "<<y + 1<<" ) : ";
				input>>num;
				matri.setvalues(x , y , num);
			}
		}
		return input;
	}

ostream& operator<<(ostream& ouput,  Matrix &matri)
	{
		int r = matri.getrows();
		int c = matri.getcolumns();

		for(int x = 0; x < r; x++)
		{
			for(int y = 0; y < c; y++)
			{
				ouput<<"Value At Index ( "<<x + 1<<" )  ( "<<y + 1<<" ) : ";
				ouput<<matri.getvalues(x , y);
				cout<<endl;
			}
		}
		return ouput;
	}

