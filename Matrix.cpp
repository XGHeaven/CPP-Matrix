#include "Matrix.hpp"
#include <iostream>

Matrix :: Matrix(int N,int M){
	I = 0;
	n = N;
	m = M;
	c = new int *[N];
	for (int i=0;i<N;i++)
		c[i] = new int[M];
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			c[i][j] = 0;
}

Matrix :: Matrix(const Matrix & M){
	I = M.I;
	n = M.n;
	m = M.m;
	c = new int * [n];
	for (int i=0;i<n;i++) c[i] = new int [m];
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++) c[i][j] = M.c[i][j];
}

Matrix :: ~Matrix(){
	for (int i=0;i<n;i++) delete [] c[i];
	delete c;
}

Matrix & Matrix :: put (int x){
	if (I>n*m) return *this;
	c[I/m][I%m] = x;
	I++;
	return *this;
}

void Matrix :: print (const char * space, const char * endl) const {
	for (int i=0;i<n;i++){
		for (int j=0;j<m-1;j++) std::cout<<c[i][j]<<space;
		std::cout<<c[i][m-1]<<endl;
	}
}

Matrix & Matrix :: operator *= (Matrix & Ma){
	int ** temp;
	int N = Ma.gn();
	int M = Ma.gm();
	temp = new int * [n];
	for (int i=0;i<m;i++) temp[i] = new int [M];
	for (int i=0;i<n;i++)
		for (int j=0;j<M;j++){
			temp[i][j] = 0;
			for (int k=0;k<m;k++)
				temp[i][j] += c[i][k] * Ma.get(k,j);
		}
	for (int i=0;i<n;i++) delete [] c[i];
	delete [] c;
	c = temp;
	m = M;
	return *this;
}

Matrix Matrix :: operator * (Matrix & Ma){
	int N = Ma.gn();
	int M = Ma.gm();
	Matrix temp(n,M);
	for (int i=0;i<n;i++)
		for (int j=0;j<M;j++)
			for (int k=0;k<m;k++)
				temp.get(i,j)+=c[i][k]*Ma.get(k,j);
	return temp;
}
