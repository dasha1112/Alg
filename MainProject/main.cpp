#include "Matrix.h"
#include "Vector.h"
#include <iostream>

main()
{

	int n = 3;
	TVector <int> a(3);
	a[1] = 2;
	a[0] = 1;
	a[2] = 3;
	TVector <int> b = a;
	TVector <int> c;
	std::cout << (a + b);
	std::cout << (a * b);
	c = a + b;
	std::cout << c;
}