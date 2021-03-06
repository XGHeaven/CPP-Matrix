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
		Matrix(int _n, int _m);//构造函数 
		Matrix(const Matrix &);//复制构造函数 
		~Matrix();//析构函数 
		
		Matrix & put(int);//添加元素，根据I 
		Matrix & setposi(int);//设置I的位置 
		Matrix & reset(int,int,int);//设置某个位置的元素的值 
		Matrix & reset(int p,int v){return reset(p/m,p%m,v);}//同上，不过是使用一维坐标 
		Matrix & clear(int=0);//清空，默认为0 
		
		int & get(int x,int y){return c[x][y];};//获取某个位置的值 
		int & get(int x) {return get(x/m,x%m);};//获取某个的值，一维坐标 
		int gn() const {return n;}//获取当前矩阵的高 
		int gm() const {return m;}//获取当前矩阵的宽 
		
		void print(const char * =" ",const char * ="\n") const;//打印当前矩阵 
		
	public :
		Matrix & operator *= (Matrix &);
		Matrix operator * (Matrix &);
};

#endif
