#pragma once
#include <iostream>
using namespace std;
inline int min(int a, int b)
{
	return (a <= b) ? a : b;
}

inline int min(int, int);


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
	Matrix() : line(5), collumn(5) { Create(); } //создаст 5 на 5
	Matrix(long int i) : line(i), collumn(i) { Create(); } //создаст квадратную матрицу 
	Matrix(long int i, long int j) : line(i), collumn(j) { Create(); } //нужного размера
	~Matrix()
	{
		for (int z = 0; z < line; z++)
			delete[] Matr[z];
		delete[] Matr;
	}

	// methods
	long int &Element(long int i, long int j)
	{
		if (i < line && j < collumn)
			return Matr[i][j];
		else
			cout << "Error: 1";
	}
	

	
	void MultiplyBy(long int x) //умножение матрицы на какое-то число
	{
		for (int i = 0; i < line; i++)
			for (int j = 0; j < collumn; j++)
				Matr[i][j] *= x;
	}
	//вывод на экран 
	void Display()
	{
		for (int i = 0; i < line; i++)
		{
			for (int j = 0; j < collumn; j++)
			{
				cout.width(4);//промежуток между числами
				cout << Matr[i][j];
			}
			cout << endl;
		}
	}
	// Конструктор копирования
	Matrix(const Matrix& _M)
	{
		// Создается новый объект для которого виделяется память
		// Копирование данных *this <= _M
		line = _M.line;
		collumn = _M.collumn;

		Matr = new long int* [line];
		for (int z = 0; z < line; z++)
			Matr[z] = new long int[collumn];
		
		// заполнить значениями
		for (int i = 0; i < line; i++)
			for (int j = 0; j < collumn; j++)
				Matr[i][j] = _M.Matr[i][j];
	}
	Matrix multiply(const Matrix& m) const {
		if (!(line == m.line && collumn == m.collumn))
			throw std::invalid_argument("Matrix dimension must be the same.");

		Matrix result(line, collumn);

		for (int i = 0; i < line; i++) {
			for (int j = 0; j < collumn; j++) {
				result.Matr[i][j] = Matr[i][j] * m.Matr[i][j];
			}
		}
		return result;
	}
	//оператор присвивания
	Matrix& operator = (const Matrix& a)
	{
		if (this->collumn > 0)
		{
			for (int i = 0; i < a.line; i++)
				delete[] this->Matr[i];
		}
		if (this->line > 0)
		{
			delete[] this->Matr;
		}
		this->line = a.line;
		this->collumn = a.collumn;
		this->Matr = new long int* [a.line];
		for (int i = 0; i < a.line; i++)
			this->Matr[i] = new long int[a.collumn];
		for (int i = 0; i < a.line; i++)
		{
			for (int j = 0; j < a.collumn; j++)
				this->Matr[i][j] = a.Matr[i][j];
		}
		return *this;
	}

	//вывод через <<
	friend std::ostream& operator << (std::ostream& out, Matrix& a) {
		for (int i = 0; i < a.line; i++)
		{
			for (int j = 0; j < a.collumn; j++)
			{
				out.width(4);//промежуток между числами
				out << a.Matr[i][j];
			}
			out << endl;
		}
		return out;
	}
	void summ_matrix(Matrix some)
	{
		for (int i = 0; i < min(line, some.line); i++)
			for (int j = 0; j < min(collumn, some.collumn); j++)
				Matr[i][j] += some.Matr[i][j];
	}

	
	//Matrix& operator * (const Matrix& a)
	//{
	//	/*if (this->collumn != a.line)
	//	{
	//		throw exception("Matrices are incompatible");
	//	}*/
	//	Matrix result(this->line, a.collumn);

	//	for (int i = 0; i < this->line; i++){
	//		for (int j = 0; j < a.collumn; j++) {
	//			for (int k = 0; k < this->collumn; k++) {
	//				/*cout << this->Matr[i][k] << " ";
	//				cout << a.Matr[k][j] << " ";*/
	//				result.Matr[i][j] += this->Matr[i][k] * a.Matr[k][j];
	//				/*result.Element(i, j) = (this->Matr[i][k] * a.Matr[k][j]);*/
	//				cout << result;
	//			}
	//		}
	//	}
	//	return result;
	//}
	Matrix Matrix ::operator *(Matrix& b) {
		Matrix c(this->line, b.collumn);
		for (int k = 0; k < line; k++) {
			for (int i = 0; i < collumn; i++)
			{
				c.Matr[k][i] = 0;
				for (int j = 0; j < b.line; j++) {
					c.Matr[k][i] += (Matr[k][j] * b.Matr[j][i]);
				}
			}
		}
		return c;
	}
};

