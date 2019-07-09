# array

原型

```c++
template < class T, size_t N > class array;
```



## 创建

```C++
//默认构造函数 无参
array<T,N> C

//复制构造函数 显示
array<T,N> c(c2)

//复制构造函数 隐式复制
array<T,N> c = c1

//移动构造函数; 拿走右值rv的元素创建一个新的数组 
array<T,N> c(rv) 

//移动构造函数; 拿走右值rv的元素创建一个新的数组
array<T,N> c = rv 

//使用初始化列表创建一个初始化的数组
array<T,N> c = initlist 
```

非变动操作

```C++
c.empty() //判断容器是否为空，与size()==0相同，但可能更快

c.size() //返回当前元素数量

c.max_size() //返回可容纳的元素最大数量

c1 == c2 //判断c1与c2是否相等

c1 != c2 //判断c1与c2是否不相等，等同于!(c1==c2)

c1 < c2 //判断c1是否小于c2

c1 > c2 //判断c1是否大于c2

c1 <= c2 //判断c1是否小于等于c2

c1 >= c2 //判断c1是否大于等于c2

```

## **赋值**

```C++
c = c2 //将c2所有元素赋值给c

c = rv //将右值对象rv的所有元素移动赋值给c

c.fill(val) //将val赋值给数组c里的每个元素

c1.swap(c2) //交换c1和c2的数

swap(c1,c2) //交换c1和c2的数
```

## **元素存取**

```C++
c[idx] //返回索引idx所标示的元素，不进行范围检查

c.at(idx) //返回索引idx所标示的元素，如果越界，抛出range-error

c.front() //返回第一个元素，不检查第一个元素是否存在

c.back() //返回最后一个元素，不检查最后一个元素是否存在
```

array 是固定大小的顺序容器，它们保存了一个以严格的线性顺序排列的特定数量的元素。

| 方法                         | 含义                                                         |
| ---------------------------- | ------------------------------------------------------------ |
| begin                        | 返回指向数组容器中第一个元素的迭代器                         |
| end                          | 返回指向数组容器中最后一个元素之后的理论元素的迭代器         |
| rbegin                       | 返回指向数组容器中最后一个元素的反向迭代器                   |
| rend                         | 返回一个反向迭代器，指向数组中第一个元素之前的理论元素       |
| cbegin                       | 返回指向数组容器中第一个元素的常量迭代器（const_iterator）   |
| cend                         | 返回指向数组容器中最后一个元素之后的理论元素的常量迭代器（const_iterator） |
| crbegin                      | 返回指向数组容器中最后一个元素的常量反向迭代器（const_reverse_iterator） |
| crend                        | 返回指向数组中第一个元素之前的理论元素的常量反向迭代器（const_reverse_iterator） |
| size                         | 返回数组容器中元素的数量                                     |
| max_size                     | 返回数组容器可容纳的最大元素数                               |
| empty                        | 返回一个布尔值，指示数组容器是否为空                         |
| operator[]                   | 返回容器中第 n（参数）个位置的元素的引用                     |
| at                           | 返回容器中第 n（参数）个位置的元素的引用                     |
| front                        | 返回对容器中第一个元素的引用                                 |
| back                         | 返回对容器中最后一个元素的引用                               |
| data                         | 返回指向容器中第一个元素的指针                               |
| fill                         | 用 val（参数）填充数组所有元素                               |
| swap                         | 通过 x（参数）的内容交换数组的内容                           |
| get（array）                 | 形如 `std::get<0>(myarray)`；传入一个数组容器，返回指定位置元素的引用 |
| relational operators (array) | 形如 `arrayA > arrayB`；依此比较数组每个元素的大小关系       |

## 访问

```C++
#include <iostream>
#include <array>

int main()
{
    std::array<int,5> myarray = {1,2,3,4,5};
   	std::cout<< myarray[0] <<std::endl;
}

```







## 遍历(迭代器)

### begin和end

```C++
#include <array>

//ydb is namespace
void ydb::arraytest()
{
    array<int,5> myarray = {1,2,3,4,5};
    for(array<int,5>::iterator it = myarray.begin();it != myarray.end();++it)
        cout<<' '<< *it;
    cout<<"\n";
}
/*
output:

1 2 3 4 5
*/

```

### rbegin和rend

```C++
#include <array>

//ydb is namespace
void ydb::arraytest()
{
    array<int,5> myarray = {1,2,3,4,5};
    for(array<int,5>::reverse_iterator it = myarray.begin();it != myarray.end();++it)
        cout<<' '<< *it;
    cout<<"\n";
}
/*
output:
5 4 3 2 1
*/
```

### cbegin和cend

```C++
#include <iostream>
#include <array>

int main ()
{
    std::array<int,5> myarray = {2, 16, 77, 34, 50};
    
    std::cout << "myarray contains:";

    for (array<int,5>::const_iterator it = myarray.cbegin(); it != myarray.cend(); ++it )
        std::cout << ' ' << *it;   // cannot modify *it

    std::cout << '\n';

    return 0;
}
```

Output

```
myarray contains: 2 16 77 34 50
```

### crbegin和crend

```C++
#include <iostream>
#include <array>

int main ()
{
    std::array<int,5> myarray = { 15, 720, 801, 1002, 3502 };

    std::cout << "myarray contains:";
    for (array<int,5>::const_reverse_iterator  it = myarray.cbegin(); it != myarray.cend(); ++it )
        std::cout << ' ' << *it;   // cannot modify *it

    std::cout << '\n';

    return 0;
}
```

Output

```
myarray contains: 2 16 77 34 50
```

## 其他算法

```C++
#include <iostream>
#include <array>
using namespace std;
int main()
{
	std::array<int, 5> myarray = { 1,2,3,4,5 };
	std::cout << myarray[0] << std::endl;
	cout << "myarray size is " << myarray.size() << endl;	//元素个数
	cout << "myarray max_size is " << myarray.max_size() << endl;
	cout<< "myarray at 3 is " << myarray.at(0) <<endl;			//返回第一个元素的引用
	cout << "myarray data is " << *(myarray.data()) << endl;   //返回第一个元素的指针
    
    myarray.fill(2); //将所有元素置成2
	for (auto it = myarray.begin();it != myarray.end();it++)
		cout<< *it <<endl;
    
	getchar();
}
```

