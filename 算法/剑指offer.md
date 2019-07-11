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

2 