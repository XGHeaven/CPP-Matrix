/*
 * Matrix
 */

#ifndef MATRIX
#define MATRIX

#include <cstring>

class Matrix{
	private :
		int n;
		int m;
		int ** c;
		int I;
	
	public :
		Matrix(int _n, int _m);
		Matrix(const Matrix &);
		~Matrix();
		Matrix & put(int);
		Matrix & setposi(int);
		Matrix & reset(int x,int y,int v){return reset(x*y,v);};
		Matrix & reset(int,int);
		Matrix & clear(int=0);
		int & get(int x,int y){return c[x][y];};
		int & get(int x) {return get(x/m,x%m);};
		int gn() const {return n;}
		int gm() const {return m;}
		void print(const char * =" ",const char * ="\n") const;
		
	public :
		Matrix & operator *= (Matrix &);
		Matrix operator * (Matrix &);
};

#endif
