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
	int size; // ������ �������
public:
	TVector(const int s = 1); //�����������
	TVector(T* arr, int s); //�����������
	TVector(const TVector<T>& p); // ����������� �����������
	~TVector(); //����������
	TVector(TVector<T>&& p); //����������� �����������

	int operator==(TVector& p); // ���������
	TVector& operator= ( TVector& p); // �������������
	TVector& operator= ( TVector&& p); //���������� � ������������
	T& operator[] (const int index); //����������
	// ��������� ��������
	TVector operator+ ( TVector<T>& p); // ��������
	TVector operator- (TVector<T>& p); // ���������
	TVector operator* (TVector<T>& p); // ��������� ������������
	TVector operator + (double a); //�������� � �����
	void Resize(int newsize = 0);
	int Size();
	// ����-�����
	template <class T1>
	friend std :: ostream& operator<< (std :: ostream& ostr, const TVector<T1> &A);
	template <class T1>
	friend std :: istream& operator >> (std :: istream& istr, TVector<T1> &A);

	
};

template <class T>

TVector <T> ::TVector(const int s) //�����������
{
	if (s == 0)
	{
		size = 0;
		data = nullptr;
	}
	else if (s < 0)
	{
		throw ("������!");
	}
	else
	{
		data = new T[s];
		size = s;
	}
}

template <class T>

TVector <T> ::TVector(T* arr, int s) //�����������
{
	if (s <= 0) throw ("������!");
	if (arr != nullptr) throw ("������");

	data = new T[s];
	size = s;

	for (int i = 0; i < size; i++)
	{
		data[i] = arr[i];
	}
}


template <class T>
TVector <T> ::TVector(const TVector<T>& p) //����������� �����������
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
TVector <T> ::TVector(TVector<T>&& p) //����������� �����������
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
TVector <T> :: ~TVector()  //����������
{
	if (data != nullptr)
	{
		size = 0;
		data = nullptr;
	}
}

template <class T>
TVector <T> TVector <T> :: operator* (TVector<T>& p) //��������� ��������
{
	if (size != p.size)
	{
		throw "������";
	}
	TVector <T> vec(size);
	for (int i = 0; i < size; i++)
	{
		vec[i] = (*this)[i] * p[i];
	}
	return vec;
}


template <class T>
TVector <T> TVector <T> :: operator- (TVector<T>& p) //��������� ��������
{
	if (size != p.size)
	{
		throw "������";
	}
	TVector <T> vec(size);
	for (int i = 0; i < size; i++)
	{
		vec[i] = (*this)[i] - p[i];
	}
	return vec;
}

template <class T>
TVector <T> TVector <T> :: operator + (TVector<T>& p) //�������� ��������
{
	if (size != p.size)
	{
		throw "������";
	}
	TVector <T> vec(size);
	for (int i = 0; i < size; i++)
	{
		vec.data[i] = data[i] + p.data[i];
	}
	return vec;
}

template <class T>
TVector <T>& TVector <T> :: operator = ( TVector<T>& p) //������������
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
TVector <T>& TVector <T> :: operator = ( TVector<T>&& p) //������������ � ������������
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
T& TVector<T> :: operator[] (const int index) //���������
{
	if (index<0 || index>=size)
	{
		throw ("������");
	}
	if (data == nullptr)
	{
		throw ("������");
	}
	return data[index];
}

template <class T>
TVector <T> TVector <T> :: operator + (double a) //�������� � ������
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
std :: ostream& operator<< (std :: ostream& ostr, const TVector<T1>& A) //�������� ������
{
	for (int i = 0; i < A.size; i++)
	{
		ostr << A.data[i] << " ";
	}
	return ostr;
}

template <class T1>
std :: istream& operator >> (std :: istream& istr, TVector<T1>& A) // �������� ����� 
{
	for (int i = 0; i < A.size; i++)
	{
		istr >> A.data[i];
	}
	return istr;
}

template <class T> //������ �������
int TVector <T> ::Size()
{
	return size;
}

template <class T>
void TVector<T>::Resize(int newSize)
{
	if (newSize < 0)
	{
		throw "������";
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

