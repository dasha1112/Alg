#ifndef _VECTOR_
#define _VECTOR_

#include <stdio.h>
#include <iostream>
using namespace std;
template <class T>
class TVector
{
protected:
	T* data;
	int size; // размер вектора
public:
	TVector(const int s = 1); //конструктор
	TVector(T* arr, int s); //конструктор
	TVector(const TVector<T>& p); // конструктор копирования
	~TVector(); //деструктор
	TVector(TVector<T>&& p); //конструктор перемещения

	int operator==(TVector& p); // сравнение
	TVector& operator= ( TVector& p); // присванивание
	TVector& operator= ( TVector&& p); //присваение с перемещением
	T& operator[] (const int index); //индексация
	// векторные операции
	TVector operator+ ( TVector<T>& p); // сложение
	TVector operator- (TVector<T>& p); // вычитание
	TVector operator* (TVector<T>& p); // скалярное произведение
	TVector operator + (double a); //сложение с чилом
	void Resize(int newsize = 0);
	int Size();
	// ввод-вывод
	template <class T1>
	friend std :: ostream& operator<< (std :: ostream& ostr, const TVector<T1> &A);
	template <class T1>
	friend std :: istream& operator >> (std :: istream& istr, TVector<T1> &A);

	
};

template <class T>

TVector <T> ::TVector(const int s) //конструктор
{
	if (s == 0)
	{
		size = 0;
		data = nullptr;
	}
	else if (s < 0)
	{
		throw ("Ошибка!");
	}
	else
	{
		data = new T[s];
		size = s;
	}
}

template <class T>

TVector <T> ::TVector(T* arr, int s) //конструктор
{
	if (s <= 0) throw ("Ошибка!");
	if (arr != nullptr) throw ("Ошибка");

	data = new T[s];
	size = s;

	for (int i = 0; i < size; i++)
	{
		data[i] = arr[i];
	}
}


template <class T>
TVector <T> ::TVector(const TVector<T>& p) //конструктор копирования
{
	if (p.data == nullptr)
	{
		size = 0;
		data = nullptr;
	}
	else
	{
		size = p.size;
		data = new T[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = p.data[i];
		}
	}
}

template <class T>
TVector <T> ::TVector(TVector<T>&& p) //конструктор перемещения
{
	data = p.data;
	size = p.size;
	if (data != nullptr) 
	{
		p.size = 0;
		p.data = nullptr;
	}
}

template <class T>
TVector <T> :: ~TVector()  //деструктор
{
	if (data != nullptr)
	{
		size = 0;
		data = nullptr;
	}
}

template <class T>
TVector <T> TVector <T> :: operator* (TVector<T>& p) //умножение векторов
{
	if (size != p.size)
	{
		throw "Ошибка";
	}
	TVector <T> vec(size);
	for (int i = 0; i < size; i++)
	{
		vec[i] = (*this)[i] * p[i];
	}
	return vec;
}


template <class T>
TVector <T> TVector <T> :: operator- (TVector<T>& p) //вычитание векторов
{
	if (size != p.size)
	{
		throw "Ошибка";
	}
	TVector <T> vec(size);
	for (int i = 0; i < size; i++)
	{
		vec[i] = (*this)[i] - p[i];
	}
	return vec;
}

template <class T>
TVector <T> TVector <T> :: operator + (TVector<T>& p) //сложение векторов
{
	if (size != p.size)
	{
		throw "Ошибка";
	}
	TVector <T> vec(size);
	for (int i = 0; i < size; i++)
	{
		vec.data[i] = data[i] + p.data[i];
	}
	return vec;
}

template <class T>
TVector <T>& TVector <T> :: operator = ( TVector<T>& p) //присваивание
{
	if (this == &p)
	{
		return *this;
	}
	if (data != nullptr)
	{
		delete[] data;
	}
	if (p.data == nullptr)
	{
		data = nullptr;
		size = 0;
		return *this;
	}
	data = new T[p.size];
	size = p.size;
	for (int i = 0; i < size; i++)
	{
		data[i] = p.data[i];
	}
	return *this;
}

template <class T>
TVector <T>& TVector <T> :: operator = ( TVector<T>&& p) //присваивание с перемещением
{
	if (this != &p)
	{
		if (data != nullptr)
			delete[] data;
		data = p.data;
		size = p.size;

		p.data = nullptr;
		p.size = 0;
			
	}
	return *this;
}

template <class T>
T& TVector<T> :: operator[] (const int index) //индексаци
{
	if (index<0 || index>=size)
	{
		throw ("Ошибка");
	}
	if (data == nullptr)
	{
		throw ("Ошибка");
	}
	return data[index];
}

template <class T>
TVector <T> TVector <T> :: operator + (double a) //сложение с числом
{
	if (data != nullptr)
	{
		TVector <T> b(size);
		for (int i = 0; i < size; i++)
		{
			b[i] = (*this)[i] + a;
		}
	}
	return b;
}


template <class T1>
std :: ostream& operator<< (std :: ostream& ostr, const TVector<T1>& A) //оператор вывода
{
	for (int i = 0; i < A.size; i++)
	{
		ostr << A.data[i] << " ";
	}
	return ostr;
}

template <class T1>
std :: istream& operator >> (std :: istream& istr, TVector<T1>& A) // Оператор ввода 
{
	for (int i = 0; i < A.size; i++)
	{
		istr >> A.data[i];
	}
	return istr;
}

template <class T> //размер массива
int TVector <T> ::Size()
{
	return size;
}

template <class T>
void TVector<T>::Resize(int newSize)
{
	if (newSize < 0)
	{
		throw "Ошибка";
	}

	if (newSize == 0)
	{
		size = 0;
		data = nullptr;
	}
	else
	{
		T* newData = new T[newSize]; 
		for (int i = 0; i < newSize; i++)
		{
			newData[i] = data[i]; 
		}
		delete[] data;  
		data = newData; 
		size = newSize;  
	}
}

#endif

