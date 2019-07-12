## vector

vector 是一种序列容器，是对大小可变数组的封装。 

vector 是表示可以改变大小的数组的序列容器。



数组中的元素是连续存储的，所以除了能够通过迭代器访问外，还可以通过常规的指针偏移量访问元素，可以将指向vector元素的指针传入以指向数组元素的指针作为参数的函数。

vector会在需要时自动调整所占内存的大小，与对应的静态数组相比，vector所占的内存通常要更多，因为它还分配了额外的内存以应对将来可能的扩张，于是，vector就不必在每次插入元素时都重新分配一次内存，除非这块预留的内存用尽。已分配内存的总大小可以通过capacity()函数查询。所占的额外的内存可以通过调用shrink_to_fit()返还给系统。

从性能方面考虑，内存重分配操作的代价通常很大，如果事先知道元素个数，可以使用reserve()函数消除重新分配操作。





| 方法                          | 含义                                                         |
| ----------------------------- | ------------------------------------------------------------ |
| vector                        | 构造函数                                                     |
| ~vector                       | 析构函数，销毁容器对象                                       |
| operator=                     | 将新内容分配给容器，替换其当前内容，并相应地修改其大小       |
| begin                         | 返回指向容器中第一个元素的迭代器                             |
| end                           | 返回指向容器中最后一个元素之后的理论元素的迭代器             |
| rbegin                        | 返回指向容器中最后一个元素的反向迭代器                       |
| rend                          | 返回一个反向迭代器，指向中第一个元素之前的理论元素           |
| cbegin                        | 返回指向容器中第一个元素的常量迭代器（const_iterator）       |
| cend                          | 返回指向容器中最后一个元素之后的理论元素的常量迭代器（const_iterator） |
| crbegin                       | 返回指向容器中最后一个元素的常量反向迭代器（const_reverse_iterator） |
| crend                         | 返回指向容器中第一个元素之前的理论元素的常量反向迭代器（const_reverse_iterator） |
| size                          | 返回容器中元素的数量                                         |
| max_size                      | 返回容器可容纳的最大元素数                                   |
| resize                        | 调整容器的大小，使其包含 n（参数）个元素                     |
| capacity                      | 返回当前为 vector 分配的存储空间（容量）的大小               |
| empty                         | 返回 vector 是否为空                                         |
| reserve                       | 请求 vector 容量至少足以包含 n（参数）个元素                 |
| shrink_to_fit                 | 要求容器减小其 capacity（容量）以适应其 size（元素数量）     |
| operator[]                    | 返回容器中第 n（参数）个位置的元素的引用                     |
| at                            | 返回容器中第 n（参数）个位置的元素的引用                     |
| front                         | 返回对容器中第一个元素的引用                                 |
| back                          | 返回对容器中最后一个元素的引用                               |
| data                          | 返回指向容器中第一个元素的指针                               |
| assign                        | 将新内容分配给 vector，替换其当前内容，并相应地修改其 size   |
| push_back                     | 在容器的最后一个元素之后添加一个新元素                       |
| pop_back                      | 删除容器中的最后一个元素，有效地将容器 size 减少一个         |
| insert                        | 通过在指定位置的元素之前插入新元素来扩展该容器，通过插入元素的数量有效地增加容器大小 |
| erase                         | 从 vector 中删除单个元素（`position`）或一系列元素（`[first，last)`），这有效地减少了被去除的元素的数量，从而破坏了容器的大小 |
| swap                          | 通过 x（参数）的内容交换容器的内容，x 是另一个类型相同、size 可能不同的 vector 对象 |
| clear                         | 从 vector 中删除所有的元素（被销毁），留下 size 为 0 的容器  |
| emplace                       | 通过在 position（参数）位置处插入新元素 args（参数）来扩展容器 |
| emplace_back                  | 在 vector 的末尾插入一个新的元素，紧跟在当前的最后一个元素之后 |
| get_allocator                 | 返回与vector关联的构造器对象的副本                           |
| swap(vector)                  | 容器 x（参数）的内容与容器 y（参数）的内容交换。两个容器对象都必须是相同的类型（相同的模板参数），尽管大小可能不同 |
| relational operators (vector) | 形如 `vectorA > vectorB`；依此比较每个元素的大小关系         |

### 定义

```C++
namespace std 
{
    template <typename T,typename Allocator = allocator<T> >
	class vector;
}
```

### 构造、复制与析构

```C++
vector<Elem> c //默认构造函数；创建一个空vector

vector<Elem> c(c2) //复制构造函数；创建一个新的vector作为c2的副本（所有元素都被复制）

vector<Elem> c = c2 //复制构造函数；创建一个新的vector作为c2的副本（所有元素都被复制）

vector<Elem> c(rv) //移动构造函数；使用右值对象rv创建一个新vector

vector<Elem> c = rv //移动构造函数；使用右值对象rv创建一个新vector

vector<Elem> c(n) //使用默认构造函数创建含有n个元素的vector

vector<Elem> c(n,elem) //创建一个vector，并使用n个elem进行初始化

vector<Elem> c(beg,end) //创建一个vector，并使用beg到end范围内的值进行初始化

vector<Elem> c(initlist) //创建一个vector，并使用初始化列表进行初始化

vector<Elem> c = initlist //创建一个vector，并使用初始化列表进行初始化

c.~vector() //销毁所有元素并释放内存
```

### 非变动性操作

```C++
c.empty() //判断容器是否为空，与size()==0相同，但可能更快

c.size() //返回当前元素数量

c.max_size() //返回可容纳的元素最大数量

c.capacity() //返回在不重新分配的情况下可容纳的元素的最大数量

c.reserve(num) //如果容量不够，进行扩大

c.shrink_to_fit() //按要求根据元素的数量去缩小容量

c1 == c2 //判断c1与c2是否相等

c1 != c2 //判断c1与c2是否不相等，等同于!(c1==c2)

c1 < c2 //判断c1是否小于c2

c1 > c2 //判断c1是否大于c2

c1 <= c2 //判断c1是否小于等于c2

c1 >= c2 //判断c1是否大于等于c2
```

### **赋值**

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

### **迭代器相关函数**

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

c.insert(pos,elem) //在迭代器位置前面插入一个elem副本，并返回新元素的位置

c.insert(pos,n,elem) //在迭代器位置前面插入n个elem副本，并返回第一个新元素的位置；若无新插入值，返回原位置

c.insert(pos,beg,end) //在迭代器位置前面插入范围beg到end的所有元素的副本，并返回第一个新元素的位置；若无新插入值，返回原位置

c.insert(pos,initlist) //在迭代器位置前面插入初始化列表的所有元素的副本，并返回第一个新元素的位置；若无新插入值，返回原位置

c.emplace(pos,args...) //在迭代器位置前面插入一个使用args初始化的元素副本，并返回新元素的位置

c.emplace_back(args...) //在末尾添加一个使用args初始化的元素副本，无返回值

c.erase(pos) //移除迭代器位置的元素，并返回下个元素的位置

c.erase(beg,end) //移除beg到end范围内的所有元素，并返回下个元素的位置

c.resize(num) //将元素数量设为num（如果size()增大，多出来的元素使用默认构造函数创建）

c.resize(num,elem) //将元素数量设为num（如果size()增大，多出来的元素都是elem的副本）

c.clear() //移除所以元素，清空容器
```





