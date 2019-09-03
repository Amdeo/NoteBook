### 1 赋值运算符函数

> 如下为类型CMyString的声明，请为该类型添加赋值运算符函数
>
> ```C++
> class CMyString
> {
> public:
>     CMyString(char * pDate = nullptr);
>     CMyString(const CMyString& str);
>     ~CMyString(void);
>     
> private:
>     char* m_pDate;
> }
> ```

```C++
CMyString& CMyString::operate=(const CMyString &str)
{
    
    //判断入参是否是当前实例
    if(this != &str)
    {
        //创建一个临时的实例，用来释放
        CMyString strTemp(str);
       	
        char * pTemp = strtemp.m_pDate;
        strtemp.m_pDate = m_pDate;
        m_pDate = pTemp;
    }
    return *this;
}
```

[Mystring](https://github.com/Amdeo/NoteBook/blob/master/C%20C%2B%2B/%E4%BB%A3%E7%A0%81/Mystring.MD)

# 2 四种强制类型转换

C语言的强制转换

```
TypeName b = (TypeName)a;
```

当前，C++也是支持C风格的强制转换，但是C风格的强制转换可能带来一些隐患。

C++四种强制转换类型函数

**1 const_cast**

常量指针被转化成非常量的指针，并且仍然指向原来的对象；

常量引用被转换成非常量的引用，并且仍然只想原来的对象；

const_cast一般用于修改指针。

```C++
int ary[4] = { 1,2,3,4 };

// 常量化数组指针
const int*c_ptr = ary;

// 通过const_cast<Ty> 去常量
int *ptr = const_cast<int*>(c_ptr);
```



**2 static_cast**

1. static_cast作用和C语言风格强制转换的效果基本一样，由于没有运行时类型检查来保证转换的安全性，所有这类型的强制转换和C语言风格的强制转换都有安全隐患。

2. 用于类层次结构中基类（父类）和派生类（子类）之间指针或引用的转换。注意：进行上行转换（把派生类的指针或引用转换成基类表示）是安全的；进行下行转换（把基类指针或引用转换成派生类表示）是，由于没有动态类型检查，所以是不安全的。

3. 用于基本数据类型之间的转换，如把int转换为char，把int转换成enum。这种转换的安全性需要开发者来维护。

4. static_cast不能转换掉原有类型的const、volatile、或者__unaligned属性。（前两种可以使用const_cast来去除）

5. C++的任何隐式转换都是使用static_cast来实现。

```C++
//常规使用方法
float f_pi = 3.14
int i_pi = static_cast<int>(f_pi);

class Base{

};

class Sub:public Base
{

}

Sub sub;
Base *base_ptr = static_cast<Base*>(&sub);

Base base;
Sub *sub_ptr = static_cast<Sub*>(&base);
```



**3 dynamic_cast**

dynamic_cast强制转换，是四个钟最特殊的一个，因为他涉及到面向对象的多态性和程序运行时的状态，也与编译器的属性设置有关，所有不能完全使用C语言的强制转换替代，它也是最常用的，最不可缺少的一种强制转换。

相比较static_cast，dynamic_cast会带来较大的性能损耗。



**4 reinterpret_cast**

reinterpret_cast是强制类型转换符用来处理无关类型转换的，通常为操作数的位模式提供较低层次的重新编译，但是他仅仅是重新解释了给出的对象的比特模型，并没有进行二进制的转换。

他是用在任意的指针之间的转换，引用之间的转换，指针和足够大的int型之间的转换、整数到指针的转换

```C++
#include<iostream>
#include<cstdint>
using namespace std;
int main() {
    int *ptr = new int(233);
    uint32_t ptr_addr = reinterpret_cast<uint32_t>(ptr);
    cout << "ptr 的地址: " << hex << ptr << endl
        << "ptr_addr 的值(hex): " << hex << ptr_addr << endl;
    delete ptr;
    return 0;
}
/*
ptr 的地址: 0061E6D8
ptr_addr 的值(hex): 0061e6d8
*/
```

# 3 回调函数

参考：https://www.cnblogs.com/tinaluo/p/8327880.html

