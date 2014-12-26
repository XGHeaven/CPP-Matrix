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

Matrix & Matrix :: put (int v){
	if (I>=n*m){
		std::cerr<<"This Matrix is full ,value = "<<v<<std::endl;
		return *this;
	}
	
	c[I/m][I%m] = v;
	I++;
	
	return *this;
}

Matrix & Matrix :: put(int * number, int length){
	for (int i=0;i<length;i++) this->put(number[i]);
	return *this;
}

Matrix & Matrix :: setposi(int i){
	I = i;
	
	return *this;
}

Matrix & Matrix::set(int x, int y, int v){
	if (x<0 || x>n-1 || y<0 || y>n-1) return *this;
	
	c[x][y] = v;
	
	return *this;
}

Matrix & Matrix::clear(int v){
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			c[i][j] = v;
	I = J = 0;
}

void Matrix :: print (const char * space, const char * endl) const {
	for (int i=0;i<n;i++){
		for (int j=0;j<m-1;j++) std::cout<<c[i][j]<<space;
		std::cout<<c[i][m-1]<<endl;
	}
}

Matrix & Matrix :: operator *= (Matrix & Ma){
	if (m != Ma.n){
		std::cerr<<"Matrix can't mul"<<std::endl;
		return *this;
	}
	int ** temp;
	int N = Ma.n;
	int M = Ma.m;
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
	if (m != Ma.n){
		std::cerr<<"Matrix can't mul"<<std::endl;
		return *this;
	}
	
	int N = Ma.n;
	int M = Ma.m;
	Matrix temp(n,M);
	for (int i=0;i<n;i++)
		for (int j=0;j<M;j++)
			for (int k=0;k<m;k++)
				temp.get(i,j)+=c[i][k]*Ma.get(k,j);
	return temp;
}

Matrix & Matrix :: operator = (Matrix & Ma){
	if (n!=Ma.n || m!=Ma.m){
		std::cerr<<"Matrix's row or line is different"<<std::endl;
		return *this;
	}
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			c[i][j]=Ma.c[i][j];
	return *this;
} 

int Matrix :: next () {
	J++;
	if (J>=n*m) J = n*m;
	return c[(J-1)/m][(J-1)%m];
}
