#include <iostream>
#include "class.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	//Vec a = Vec(10), b = Vec(10), c = Vec(10);

	//for (int i = 0; i < 10; i++)
	//{
	//	a.arr[i] = i;
	//	b.arr[i] = i;
	//}

	//cout <<"Вектор 1: " <<a;
	//cout <<"Вектор 2: " << b;
	///*a.print();
	//b.print();*/
	//c = a + b;
	///*c.print();*/
	//cout <<"Сумма векторов: "<< c; //оператор переопределён
	//

	//
	
	int line=3;
	/*cout << "Количество строк: "; cin >> line;*/
	int collumn=3;
	//cout << "Количество столбцов: "; cin >> collumn;
	
	Matrix M(line, collumn);

	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < collumn; j++)
			M.Element(i, j) = i+j;
	}

	cout << M;


	Matrix L(line, collumn);
	L = M;
	L.MultiplyBy(5);

	cout << "\n After multiply by 5\n" << endl;
	cout << L;
	
	L.multiply(M);
	cout << L;
	
	//cout << "\n After summ\n" << endl;
	//L.summ_matrix(M);
	//cout << L;

	/*cout << "\n After multiply \n" << endl;
	M = M * L;
	cout << M*L;
	*/
	return 0;
	
	

}
