#pragma once
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

class row; // ����� "������"
class matrix; // ����� "�������"

class row // ����� "������"
{
public:
	friend class matrix;
	int& operator [] (int j); // �������� ������� � ��������
	int get_sz() { return sz; }
	int* get_massiv() { return p; }
private:
	row(int a); // �����������
	int* p;
	int sz;
};

row::row(int a) : sz(a) // �����������
{
	p = new int[a];
	if (!(p != 0)) {
		throw exception("������ �� ����������");
	}
}

int& row::operator [] (int j) // �������� ������� � ��������
{
	if (!(j >= 0 && j < sz)) // �����������, �� ����� �� �� �� ������� �������
	{
		throw exception("����� �� ������� �������");
	}
	return p[j];
}

class matrix // ����� "�������"
{
public:
	matrix(int a, int b); // �����������, a-���������� ��������
	matrix(const matrix& m); // ���������� �����������
	~matrix(); // ����������
	void init(); // �������, ���������������� ������ ����������
	void copy(row** x, int r, int c); // ������� ����������� �������
	row& operator [] (int i); // �������� ������� � ������ �������
	matrix& operator = (const matrix& m); // �������� ������������
	matrix operator + (const matrix& m); // �������� �������� ������
	matrix operator * (const matrix& m); // �������� ��������� ������
	matrix operator * (int n); // ��������� ������� �� �����
	friend matrix operator * (int n, matrix& m); // ��������� ����� �� �������
	friend ostream& operator << (ostream& out, const matrix& m); // �������� ������ ������� � �����
private:
	row** p; // ��������� �� ��������� ������
	int r; // ���������� �����
	row** create_mas(int a, int b); // �������, ���������� ������ ��� ������
	void copyMassiv(row** x, int r, int c); // �������, ���������� � ����� ������ �������� � ������ ������� 
	void erase_mas(row** x, int r); // �������, ��������� ������
};

row** matrix::create_mas(int a, int b) // �������, ���������� ������ ��� ������
{
	row** q = new row * [a];
	int i, j;
	for (i = 0; i < a; i++)
	{
		q[i] = new row(b);
		if (!(q[i] != 0)) // �����������, ���������� �� ������
		{
			throw exception("������ �� ����������");
		}
	}
	return q;
}

matrix::matrix(int a, int b) : r(a)  // �����������, a-���������� �����, b-��������
{
	p = create_mas(a, b);
}

matrix::matrix(const matrix& m) : r(m.r) // ���������� �����������
{
	p = create_mas(m.r, m.p[0]->sz);
	copy(m.p, m.r, m.p[0]->sz);
}

void matrix::copy(row** x, int r, int c) // �������, ���������� ������
{
	int i, j;

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			p[i]->p[j] = x[i]->p[j];
}

void matrix::erase_mas(row** x, int r) // �������, ��������� ������
{
	int i;
	for (i = 0; i < r; i++)
		delete[] x[i];
	delete[] x;
}

matrix::~matrix() // ����������
{
	erase_mas(p, r); // �������� �������
}

matrix& matrix::operator = (const matrix& m) // �������� ������������
{
	if (!(m.p[0]->sz == p[0]->sz && m.r == r))// �����������, ����� �� ������� ���� ������
	{
		throw exception("������� ������ �� �����");
	}
	int i, j;
	copy(m.p, m.r, m.p[0]->sz);
	return *this;
}

ostream& operator << (ostream& out, const matrix& a) // �������� ������ ������� � �����
{
	int i, j;
	for (i = 0; i < a.r; i++)
	{
		for (j = 0; j < a.p[0]->get_sz(); j++)
			out << a.p[i]->get_massiv()[j] << " ";
		out << endl;
	}
	out << endl;
	return out;
}

row& matrix::operator [] (int i) // �������� ������� � ������ �������
{
	if (!(i >= 0 && i < r)) // �����������, �� ����� �� �� �� ������� �������
	{
		throw exception("�� ����� �� ������� �������");
	}
	return *p[i];
}

matrix matrix::operator + (const matrix& m) // �������� �������� ���� ������
{
	if (!(m.p[0]->sz == p[0]->sz && m.r == r)) // �����������, ����� �� ������� ���� ������
	{
		throw exception("������� ���� ������ �� �����");
	}
	matrix n(m); // �������� ����� ������� (����� 2��)
	int i, j;
	for (i = 0; i < r; i++)
		for (j = 0; j < p[0]->sz; j++)
			n.p[i]->p[j] += p[i]->p[j]; // � ������������� ������� ������������ 1��
	return n;
}

matrix matrix::operator * (const matrix& m) // �������� ��������� ���� ������
{
	if (!(p[0]->sz == m.r)) // �����������, ����� �� ���������� �������� 1�� ������� ���������� ����� 2��
	{
		throw exception("���������� �������� 1�� ������� �� ����� ���������� ����� 2��");
	}
	matrix n(r, m.p[0]->sz); // �������� ����� ������� ������������ �������
	int i, j, k;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < m.p[0]->sz; j++)
		{
			n.p[i]->p[j] = 0;
			for (k = 0; k < p[0]->sz; k++)
				n.p[i]->p[j] += p[i]->p[k] * m.p[k]->p[j]; // ��������� ��������� ������������ � ����� �������
		}
	}
	return n;
}

matrix matrix::operator * (int n) { // �������� ��������� ������� �� �����
	matrix a(*this); // �������� ����� ������� 
	int i, j;
	for (i = 0; i < r; i++)
		for (j = 0; j < p[0]->sz; j++)
			a.p[i]->p[j] = p[i]->p[j] * n; // ������������� ������� ����������� �� �����
	return a;
}

matrix operator * (int n, matrix& m) // ��������� ����� �� �������
{
	return m * n;
}

void matrix::copyMassiv(row** x, int r, int c) // �������, ���������� � ������ �������� � ������ �������
{
	int i, j;
	for (i = 0; i < c; i++)
		for (j = 0; j < r; j++)
			x[i]->p[j] = p[j]->p[i];
}


void matrix::init() // �������, ����������� ������� ���������� ����������
{
	srand(time(0));
	int i, j;
	for (i = 0; i < r; i++)
		for (j = 0; j < p[0]->sz; j++)
			p[i]->p[j] = rand() % 6; // ������� ����������� ���������� �� 0 �� 5
}