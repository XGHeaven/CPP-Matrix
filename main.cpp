#include "Matrix.hpp"
#include <iostream>

int main(){
	Matrix a(2,3),b(3,2);
	a.put(1).put(-1).put(2).put(2).put(3).put(1);
	b.put(0).put(1).put(-1).put(2).put(3).put(1);
//	a.print();
//	b.print();
	a*=b;
	a.print();
//	std::cin.get();
//	Matrix k=a*b;
//	k.print();
	return 0;
}
