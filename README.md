这是我第一次使用git，就先拿一个C++程序来练练手把，尝试一下。

希望大家不要见怪

这个C++程序是计算矩阵乘法的。

主要思想是将矩阵类描述的像普通的类型一样，可以直接复制构造，直接相乘等功能



# 文档结构  

> * Matrix.hpp 矩阵类的声明

> * Matrix.cpp 矩阵类的定义



# 如何使用Matrix类呢？

```
#include "Matrix.hpp"
```

引用之后就可以通过如下方式使用Matrix类

```
Matrix matrix(2,2);
```

> constructor (int row, int line);

通过传入两个值的构造，创建一个row*line的矩阵，此时的值未进行初始化

对内部的值进行赋值可以通过一下两种方式

> * put方法
put方法有两种重载
```
matrix.put(int);
matrix.put(int *);
```


希望大家继续关注，我将不停的进行更新。