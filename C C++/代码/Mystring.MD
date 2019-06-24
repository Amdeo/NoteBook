# Mystring类

自定义String类



Mystring.h

```C++
class Mystring
{
    typedef int TInt4;
    
    Mystring();//默认构造函数
    Mystring(const char* str);//一个参数的构造函数
    Mystring(const Mystring &str);
    Mystring(TInt4 len,const char ch);   //2个参数构造函数
    ~Mystring();
    
   	MyString& operator=(const MyString&);
    friend MyString operator+(const MyString & str1,const MyString & str2);
private:
    char * pstr; //字符串指针
    TInt4 iSize; //字符串长度
}

```



Mystring.cpp

```C++
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include<assert.h>

Mystring::Mystring()
{
    char * pstr == NULL;
    TInt4 iSize = 0;
}

Mystring::Mystring(const char* str)
{
    if(str == NULL)
        return;
    pstr = new char[strlen(str) + 1];
    strcpy(pstr,str);
    iSize = strlen(pstr);
}

Mystring::Mystring(const Mystring &str)
{
    if(str.pstr)
    {
        pstr = new char[strlen(str.pstr) + 1];
    	strcpy(pstr,str.pstr);
    }
    else
    {
        pstr = NULL;
        iSize = 0;
    }
}

Mystring::Mystring(TInt4 len,const char ch)
{
	if(len > 0)
    {
        pstr = new char[len + 1];
        for(int i = 0;i < len;i++)
        {
			pstr[i] = ch;
        }
        pstr[len + 1] = '\0';
        iSize = len;
    }
}

MyString::MyString& operator=(const MyString& str);
{
    if(this != &str)
    {
        MyString strTemp(str);
        char *pTemp = strTemp.pstr;
        strTemp.pstr = this->pstr;
        this->pstr = pTemp;
    }
    return *this;
}

MyString operator+(const MyString & str1, const MyString & str2)
{
	MyString temp;
	temp.iSize = str1.iSize + str2.iSize;
	temp.ptr = new char[temp.iSize + 1];
	
	strncpy(temp.ptr, str1.ptr,str1.iSize+1);
	strcat(temp.ptr, str2.ptr);

	return temp;
}
```



### 为什么重载友元函数？

C++运算符重载可采用成员函数和友元函数，二者都可以访问类的私有成员，那么该采用哪一种呢？首先看一下二者的区别。

（1）当重载为成员函数时，会隐含一个this指针；当重载为友元函数时，不存在隐含的this指针，需要在参数列表中显示地添加操作数。

（2）当重载为成员函数时，只允许右参数的隐式转换；当重载为友元函数时，能够接受左参数和右参数的隐式转换。

例如：

```C++
class Mystring
{
public:
    Mystring(char* str);
private:
    char* m_pStr;
};
```



因为Mystring的构造函数参数为一个char*，所以如果采用友元形式的operator +(const Mystring&, const Mystring&)，那么`char * + Mystring 和 Mystring + char *  `都能正常工作；

而如果采用成员函数形式Mystring::operator+(const Mystring& rhs)，则只能接受`Mystring + char *`，如果执行`char * + Mystring`则会编译出错。我们往往习惯`Mystring + char *和char * + Mystring`都应该被接受。需要注意的是，隐式转换由于临时变量的增加往往效率不高。如果应用程序对效率要求较高，针对以上类，建议选择定义多个运算符的友元重载版本：

```C++
Mystring& operator +(const Mystring&, const Mystring&);
Mystring& operator +(const char*, const Mystring&);
Mystring& operator +(const Mystring&, const char*);
```

**一般而言，对于双目运算符，最好将其重载为友元函数；而对于单目运算符，则最好重载为成员函数。** 
