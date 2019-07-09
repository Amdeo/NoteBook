# makefile

## 单文件编译

```C++
//test.cpp
#include <stdio.h>
int main()
{
	std::cout<< "hello world" <<std::endl;
    return 0;
}
```

使用命令行进行编译

```
g++ test.cpp -o test
```

使用makefile编译

1.创建一个makefile文件（`注: 没有扩展名`）

```makefile
test: test.cpp
      g++ test.cpp -o test
```

test是最终生成的目标文件

g++ test.cpp -o test 编译命令



## 多文件编译

```C++
//fun1.cpp

//查找最大值
int func1(int *a,int n)
{
    int max = a[0];
    for (int i = 1;i < n;i++)
    {
        if(max < a[i])
        {
            max = a[i]
        }
    }
    return max;
}
```

```C++
//fun1.h
extern func1(int *a,int n);
```


```C++
//main.cpp
#include <iostream>
#include "fun1.h"

int main()
{
    int a[5] = {33,11,2,5,66};
    std::cout<< func1(a,5) <<std::endl;
    return 0;
}

```

```makefile
test: test.cpp fun1.o
	g++ test.cpp fun1.o -o test
fun1.o: fun1.cpp
	g++ -c fun1.cpp
clean:
	rm *.o test
```

