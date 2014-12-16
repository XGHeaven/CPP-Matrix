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
		Matrix(int _n, int _m);//���캯�� 
		Matrix(const Matrix &);//���ƹ��캯�� 
		~Matrix();//�������� 
		
		Matrix & put(int);//���Ԫ�أ�����I 
		Matrix & setposi(int);//����I��λ�� 
		Matrix & reset(int,int,int);//����ĳ��λ�õ�Ԫ�ص�ֵ 
		Matrix & reset(int p,int v){return reset(p/m,p%m,v);}//ͬ�ϣ�������ʹ��һά���� 
		Matrix & clear(int=0);//��գ�Ĭ��Ϊ0 
		
		int & get(int x,int y){return c[x][y];};//��ȡĳ��λ�õ�ֵ 
		int & get(int x) {return get(x/m,x%m);};//��ȡĳ����ֵ��һά���� 
		int gn() const {return n;}//��ȡ��ǰ����ĸ� 
		int gm() const {return m;}//��ȡ��ǰ����Ŀ� 
		
		void print(const char * =" ",const char * ="\n") const;//��ӡ��ǰ���� 
		
	public :
		Matrix & operator *= (Matrix &);
		Matrix operator * (Matrix &);
};

#endif
