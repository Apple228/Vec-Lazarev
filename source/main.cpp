#include <iostream>
#include "class.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	Vec a = Vec(10), b = Vec(10), c = Vec(10);

	for (int i = 0; i < 10; i++)
	{
		a.arr[i] = i;
		b.arr[i] = i;
	}

	cout << a;
	cout << b;
	/*a.print();
	b.print();*/
	c = a + b;
	/*c.print();*/
	cout << c; //оператор переопределён
	

	




	double** arr;
	int line = 5;
	int collumn = 2;
	
	Matrix M(3);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			M.Element(i, j) = i + j;
	}

	M.Display();

	/*cout << "\n After multiply by 5\n" << endl;
	M.MultiplyBy(5);
	M.Display();*/

	return 0;
	
	
}
