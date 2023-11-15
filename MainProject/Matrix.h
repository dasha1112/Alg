#ifndef _MATRIX_
#define _MATRIX_

#include <iostream>
#include "Vector.h"
#include <stdio.h>
using namespace std;
template <class T>
class TMatrix : public TVector<TVector<T> >
{
public:
	TMatrix(int n = 0, int m = 0);
	TMatrix(const TMatrix& p); // копирование
	TMatrix(const TMatrix<T>&& p); // конструктор перемещения
	~TMatrix(); //деструктор 
	TMatrix operator+ (double a);
	TMatrix& operator==(TMatrix& p); // сравнение
	TMatrix& operator= (const TMatrix& p); // присваивание
	TMatrix& operator= (const TMatrix&& p); // присваивание с перемещением
	TMatrix operator+ (const TMatrix& p); // сложение
	TMatrix operator- (const TMatrix& p); // вычитание
	TMatrix operator* (const TMatrix& p); // умножение
	void Resize(int newN, int newM);
	// ввод / вывод
	friend std :: istream& operator>>(std :: istream& in, TMatrix& mt);
	friend std :: ostream& operator<<(std :: ostream& out, const TMatrix& mt);


};
template <class T>
TMatrix<T> ::TMatrix(int n, int m)
{
	if (n < 0 || m < 0)
	{
		throw "Ошибка";
	}
	if (n == 0 && m == 0)
	{
		data = nullptr;
		size = 0;
	}
	else
	{
		size = n;
		data = new TVector[size];
		for (int i = 0; i < size; i++)
		{
			data[i].Resize(m);
		}
	}
}

template <class T>
TMatrix <T> ::TMatrix(const TMatrix<T>& p)
{
	if (p.size == 0)
	{
		size = 0;
		data = nullptr;
	}
	else if (p.size < 0)
	{
		throw ("Ошибка!");
	}
	else
	{
		size = p.size;
		data = new TVector[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = p.data[i];
		}
	}
}

template <class T>
TMatrix <T> ::TMatrix(const TMatrix<T>&& p)
{
	size = p.size;
	data = p.data;
	p.data = nullptr;
	p.size = 0;
}

template <class T>
TMatrix<T> :: ~TMatrix()
{
	if (data != nullptr)
	{
		size = 0;
		data = nullptr;
	}
}

template <class T>
TMatrix <T> TMatrix <T> :: operator+ (double a)
{
	TMatrix<T> res(*this);
	for (int i = 0; i < size; i++)
	{
		if (res.data[i].Size() > i) 
		{
			res.data[i][i] += a;
		}
	}
	return res;
}
template <class T>
TMatrix <T> TMatrix <T> :: operator + (const TMatrix<T>& p) 
{
	TMatrix <T> res(*this);
	if (size != p.size) 
	{
		throw ("Ошибка");
	}
	else 
	{
		for (int i = 0; i < size; i++) 
		{
			res.data[i] = data[i] + p.data[i];
		}
	}
	return res;
}

template <class T>
TMatrix <T> TMatrix <T> :: operator - (const TMatrix<T>& p)
{
	TMatrix <T> res(*this);
	if (size != p.size)
	{
		throw ("Ошибка");
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			res.data[i] = data[i] - p.data[i];
		}
	}
	return res;
}

template <class T>
TMatrix <T> TMatrix <T> :: operator * (const TMatrix& p) 
{
	int n = (*this).Size();
	int m = mt[0].Size();
	int p = mt.Size();

	if ((*this)[0].Size() != p)
	{
		throw "Ошибка";
	}

	TMatrix<T> result(n, m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			T sum = 0;
			for (int k = 0; k < p; k++)
			{
				sum += ((*this)[i][k]) * (mt[k][j]);
			}
			result[i][j] = sum;
		}
	}

	return result;
}

template <class T>
TMatrix <T>& TMatrix<T> :: operator = (const TMatrix& p) 
{
	if (this == &p)
	{
		return *this;
	}
	if (data != nullptr)
	{
		delete[] data;
		data = new TVector <T>[size];
		size = p.size;
	}
	for (int i = 0; i < size; i++)
	{
		data[i] = p.data[i];
	}
	return *this;
}

template <class T>
TMatrix <T>& TMatrix<T> :: operator= (const TMatrix&& p) 
{
	if (data != nullptr)
		delete[] data;
	data = p.data;
	size = p.size;

	p.data = nullptr;
	p.size = 0;

	return *this;
}

template <class T> 
TMatrix <T>& TMatrix <T> ::operator== (TMatrix <T>& p) 
{
	return TVector<TVector<T>>::operator==(p);
}

template <class T>
void TMatrix<T> ::Resize(int newN, int newM) 
{
	if (newN < 0 || newM < 0)
		throw "Ошибка";
	if else (newN == 0) 
	{
		data = nullptr;
		size = 0;
	}
	else 
	{
		delete[] data;
		size = newN;
		data = new TVector <T>[size];
		for (int i = 0; i < size; i++) 
		{
			data[i].Resize(newM);
		}
	}
}

template <class T>
istream& operator>>(istream& in, TMatrix<T>& mt)
{
	return in >> (TVector<TVector<T>>&)mt;
}

template <class T>
ostream& operator<<(ostream& out, const TMatrix<T>& mt)
{
	return out << (const TVector<TVector<T>>&)mt;
}
#endif