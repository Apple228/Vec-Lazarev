#include <iostream>
#include "class.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	Vec a = Vec(10), b = Vec(10), q = Vec(10);

	for (int i = 0; i < 10; i++)
	{
		a.arr[i] = i;
		b.arr[i] = i;
	}
	cout << a;
	cout << b;
	/*a.print();
	b.print();*/
	q = a + b;
	/*c.print();*/
	cout << q; //оператор переопределён
	
	
	
	
}
