## C基础

### 赋值

> int a,b
>
> int a=1,b=2;



### 数据结构

基本数据类型：int	float	double	char	

构造数据类型：<u>struct union enum</u>



| 数据类型       | 字节 | 取值范围                                     |
| -------------- | ---- | -------------------------------------------- |
| unsigned char  | 1    | 0 ~ 2^8 - 1                                  |
| char           | 1    | - 2^7 ~ 2^7 -1                               |
| unsigned short | 2    | 0 ~ 2^16 -1                                  |
| short          | 2    | -2^15 ~ 2^15 -1                              |
| unsigned int   | 4    | 0 ~ 2^32 - 1                                 |
| int            | 4    | - 2^31 ~ 2^31 -1                             |
| unsigned long  | 8    | 0 ~ 2^64 - 1                                 |
| long           | 8    | - 2^63 ~ 2^63 - 1                            |
| float          | 4    | -3.4 *10^38～+3.4 *10^38 (有效数字 6 -7)     |
| double         | 8    | -1.7 *10^-308~1.7 *10^308(有效数字 15 -16)   |
| long double    | 12   | -1.2 *10^-4932~1.2 *10^4932(有效数字 18 -19) |



#### struct、union 、enum的大小

设置字节对齐

> #pragma pack(4)   //设置4字节对齐 等价于#pragma pack(push,2)
>
> #pragma pack()     //取消自定义字节对齐方式  等价于#pragma pack(pop)

**struct**

```C++
//4字节对齐
struct Mystruct
{
	char a		//1 + 3 不够4字节，补齐到4字节
	int b;		//4
	long c;		//4
	int d[10];	//40
}e;
/*
-------
sizeof(e)输出:52
-------
*/
```

**union**

```C++
union
{
    int a;		//4
	long b;		//4
	int c[10];	//40
}e;
/*
-------
sizeof(e)输出:40
-------
*/
```

**enum**

```C++
enum
{
	a = 1;
	b;
	c;
}d;
/*
-------
sizeof(d)输出:4
-------
*/
```

