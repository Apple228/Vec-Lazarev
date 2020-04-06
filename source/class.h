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


