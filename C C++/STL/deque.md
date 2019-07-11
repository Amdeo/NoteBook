## deque

deque（['dek]）（双端队列）是double-ended queue 的一个不规则缩写。deque是具有动态大小的序列容器，可以在两端（前端或后端）扩展或收缩。此外，在deque两端插入和删除并不会使其它元素的指针或引用失效。

| 方法          | 含义                                                         |
| ------------- | ------------------------------------------------------------ |
| deque         | 构造函数                                                     |
| push_back     | 在当前的最后一个元素之后 ，在 deque 容器的末尾添加一个新元素 |
| push_front    | 在 deque 容器的开始位置插入一个新的元素，位于当前的第一个元素之前 |
| pop_back      | 删除 deque 容器中的最后一个元素，有效地将容器大小减少一个    |
| pop_front     | 删除 deque 容器中的第一个元素，有效地减小其大小              |
| emplace_front | 在 deque 的开头插入一个新的元素，就在其当前的第一个元素之前  |
| emplace_back  | 在 deque 的末尾插入一个新的元素，紧跟在当前的最后一个元素之后 |

定义

```C++
namespace std 
{
    template <typename T,typename Allocator = allocator<T> >
		class deque;
}
```

### **deque操作**

### **构造、复制与析构**

```C++
deque<Elem> c //默认构造函数；创建一个空deque

deque<Elem> c(c2) //复制构造函数；创建一个新的deque作为c2的副本（所有元素都被复制）

deque<Elem> c = c2 //复制构造函数；创建一个新的deque作为c2的副本（所有元素都被复制）

deque<Elem> c(rv) //移动构造函数；使用右值对象rv创建一个新deque

deque<Elem> c = rv //移动构造函数；使用右值对象rv创建一个新deque

deque<Elem> c(n) //使用默认构造函数创建含有n个元素的deque

deque<Elem> c(n,elem) //创建一个deque，并使用n个elem进行初始化

deque<Elem> c(beg,end) //创建一个deque，并使用beg到end范围内的值进行初始化

deque<Elem> c(initlist) //创建一个deque，并使用初始化列表进行初始化

deque<Elem> c = initlist //创建一个deque，并使用初始化列表进行初始化

c.~deque() //销毁所有元素并释放内存
```

### **非变动性操作**

```C++
c.empty() //判断容器是否为空，与size()==0相同，但可能更快

c.size() //返回当前元素数量

c.max_size() //返回可容纳的元素最大数量

c.shrink_to_fit() //按要求根据元素的数量去缩小容量

c1 == c2 //判断c1与c2是否相等

c1 != c2 //判断c1与c2是否不相等，等同于!(c1==c2)

c1 < c2 //判断c1是否小于c2

c1 > c2 //判断c1是否大于c2

c1 <= c2 //判断c1是否小于等于c2

c1 >= c2 //判断c1是否大于等于c2

```

### 赋值

```C++
c = c2 //将c2所有元素赋值给c

c = rv //将右值对象rv的所有元素移动赋值给c

c = initlist //使用初始化列表进行赋值

c.assign(initlist) //使用初始化列表进行赋值

c.assign(n,elem) //使用n个elem元素进行赋值

c.assign(beg,end) //使用beg到end范围内的元素进行赋值

c1.swap(c2) //交换c1和c2的数

swap(c1,c2) //交换c1和c2的数

```

### 元素存取

```C++
c[idx] //返回索引idx所标示的元素，不进行范围检查

c.at(idx) //返回索引idx所标示的元素，如果越界，抛出range-error

c.front() //返回第一个元素，不检查第一个元素是否存在

c.back() //返回最后一个元素，不检查最后一个元素是否存在
```

### 迭代器相关函数

```C++
c.begin() //返回一个随机存取迭代器，指向第一个元素

c.end() //返回一个随机存取迭代器，指向最后一个元素

c.cbegin() //返回一个随机存取常迭代器，指向第一个元素

c.cend() //返回一个随机存取常迭代器，指向最后一个元素

c.rbegin() //返回一个逆向迭代器，指向逆向迭代的第一个元素

c.rend() //返回一个逆向迭代器，指向逆向迭代的最后一个元素

c.crbegin() //返回一个逆向常迭代器，指向逆向迭代的第一个元素

c.crend() //返回一个逆向常迭代器，指向逆向迭代的最后一个元素
```

### **插入和移除元素**

```C++
c.push_back(elem) //在末尾添加一个elem副本

c.pop_back() //移除末尾元素（但不回传）

c.push_front(elem) //在头部添加一个elem副本

c.pop_back() //移除头部元素（但不回传）

c.insert(pos,elem) //在迭代器位置前面插入一个elem副本，并返回新元素的位置

c.insert(pos,n,elem) //在迭代器位置前面插入n个elem副本，并返回第一个新元素的位置；若无新插入值，返回原位置

c.insert(pos,beg,end) //在迭代器位置前面插入范围beg到end的所有元素的副本，并返回第一个新元素的位置；若无新插入值，返回原位置

c.insert(pos,initlist) //在迭代器位置前面插入初始化列表的所有元素的副本，并返回第一个新元素的位置；若无新插入值，返回原位置

c.emplace(pos,args...) //在迭代器位置前面插入一个使用args初始化的元素副本，并返回新元素的位置

c.emplace_back(args...) //在末尾添加一个使用args初始化的元素副本，无返回值

c.emplace_front(args...) //在头部添加一个使用args初始化的元素副本，无返回值

c.erase(pos) //移除迭代器位置的元素，并返回下个元素的位置

c.erase(beg,end) //移除beg到end范围内的所有元素，并返回下个元素的位置

c.resize(num) //将元素数量设为num（如果size()增大，多出来的元素使用默认构造函数创建）

c.resize(num,elem) //将元素数量设为num（如果size()增大，多出来的元素都是elem的副本）

c.clear() //移除所以元素，清空容器

```

### 例子

```


```



