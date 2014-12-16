#include "Matrix.hpp"
#include <iostream>

int main(){
	Matrix a(1,2),b(2,1);
	a.put(1).put(2);
	b.put(3).put(4);
	a.print();
	b.print();
	a*=b;
	a.print();
	Matrix k=a*b;
	k.print();
	return 0;
}
