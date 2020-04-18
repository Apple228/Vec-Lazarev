#pragma once
#include <iostream>
using namespace std;

class Vec
{
public:
	double* arr;
	int size;
	Vec(int len)
	{
		size = len;
		arr = new double[len];
	}

	friend Vec operator + (Vec const& a, Vec const& b)
	{
		Vec result = Vec(a.size);
		for (int i = 0; i < a.size; i++)
		{
			result.arr[i] = a.arr[i] + b.arr[i];
		}
		return result;
	}


	void print()
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << arr[i] << " ";
		}
		std::cout << "\n";
	}

	friend std::ostream& operator << (std::ostream& out, const Vec& c);


};
std::ostream& operator << (std::ostream& out, const Vec& c)
{
	for (int i = 0; i < 10; i++)
	{
		out << c.arr[i] << " ";
	}
	out << "\n";

	return out;




}

class Matrix
{
private:
	long int** Matr;
	long int line;
	long int collumn;

	void Create()
	{
		Matr = new long int* [line];
		for (int z = 0; z < line; z++)
			Matr[z] = new long int[collumn];
	}

public:
	// constructors and destructor
	Matrix() : line(5), collumn(5) { Create(); }
	Matrix(long int i) : line(i), collumn(i) { Create(); }
	Matrix(long int i, long int j) : line(i), collumn(j) { Create(); }
	~Matrix()
	{
		for (int z = 0; z < line; z++)
			delete[] Matr[z];
		delete[] Matr;
	}

	// methods
	long int& Element(long int i, long int j)
	{
		if (i < line && j < collumn)
			return Matr[i][j];
		else
			cout << "Error: 1";
	}

	void MultiplyBy(long int x)
	{
		for (int i = 0; i < line; i++)
			for (int j = 0; j < collumn; j++)
				Matr[i][j] *= x;
	}

	void Display()
	{
		for (int i = 0; i < line; i++)
		{
			for (int j = 0; j < collumn; j++)
			{
				cout.width(4);
				cout << Matr[i][j];
			}
			cout << endl;
		}
	}

};
