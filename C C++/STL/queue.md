# queue

定义：

```C++
#include <queue>
namespace std 
{
    template <typename T, typename Container = deque<T>> class queue;
}
```

核心接口

```C++
push() //将一个元素置入queue内

front() //返回queue内头部元素

back() //返回queue内尾部元素

pop() //从queue中移除元素
```

