# list

## 定义

```C++
namespace std 
{
    template <typename T,typename Allocator = allocator<T> >
	class list;
}
```

列表是一个容器，它支持任何位置的元素快速插入和删除，不支持快速的随机访问，它被实现为双向的链表。

与forward_list相比，它提供双向迭代的能力，但空间效率更低。

插入和删除操作不会使指向其他元素指针、引用和迭代器失效。



构造、复制与析构

```C++
list<Elem> c //默认构造函数；创建一个空list

list<Elem> c(c2) //复制构造函数；创建一个新的list作为c2的副本（所有元素都被复制）

list<Elem> c = c2 //复制构造函数；创建一个新的list作为c2的副本（所有元素都被复制）

list<Elem> c(rv) //移动构造函数；使用右值对象rv创建一个新list

list<Elem> c = rv //移动构造函数；使用右值对象rv创建一个新list

list<Elem> c(n) //使用默认构造函数创建含有n个元素的list

list<Elem> c(n,elem) //创建一个list，并使用n个elem进行初始化

list<Elem> c(beg,end) //创建一个list，并使用beg到end范围内的值进行初始化

list<Elem> c(initlist) //创建一个list，并使用初始化列表进行初始化

list<Elem> c = initlist //创建一个list，并使用初始化列表进行初始化

c.~list() //销毁所有元素并释放内存

```

### **非变动性操作**

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

### **元素存取**

```C++
c.front() //返回第一个元素，不检查第一个元素是否存在

c.back() //返回最后一个元素，不检查最后一个元素是否存在
```

### **迭代器相关函数**

```C++
c.begin() //返回一个双向迭代器，指向第一个元素

c.end() //返回一个双向迭代器，指向最后一个元素

c.cbegin() //返回一个双向常迭代器，指向第一个元素

c.cend() //返回一个双向常迭代器，指向最后一个元素

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

c.pop_front() //移除头部元素（但不回传）

c.insert(pos,elem) //在迭代器位置前面插入一个elem副本，并返回新元素的位置

c.insert(pos,n,elem) //在迭代器位置前面插入n个elem副本，并返回第一个新元素的位置；若无新插入值，返回原位置

c.insert(pos,beg,end) //在迭代器位置前面插入范围beg到end的所有元素的副本，并返回第一个新元素的位置；若无新插入值，返回原位置

c.insert(pos,initlist) //在迭代器位置前面插入初始化列表的所有元素的副本，并返回第一个新元素的位置；若无新插入值，返回原位置

c.emplace(pos,args...) //在迭代器位置前面插入一个使用args初始化的元素副本，并返回新元素的位置

c.emplace_back(args...) //在末尾添加一个使用args初始化的元素副本，无返回值

c.emplace_front(args...) //在头部添加一个使用args初始化的元素副本，无返回值

c.erase(pos) //移除迭代器位置的元素，并返回下个元素的位置

c.erase(beg,end) //移除beg到end范围内的所有元素，并返回下个元素的位置

c.remove(val) //移除所有值为val的元素

c.remove_if(op) //移除所有满足op条件的元素

c.resize(num) //将元素数量设为num（如果size()增大，多出来的元素使用默认构造函数创建）

c.resize(num,elem) //将元素数量设为num（如果size()增大，多出来的元素都是elem的副本）

c.clear() //移除所以元素，清空容器
```

### **特殊修改操作**

```C++
c.unique() //若存在相邻而数值相等的元素，移除重复元素

c.unique(op) //若存在相邻而数值相等的元素，且满足op条件时，移除重复元素

c.splice(pos,c2) //将c2内的所有元素转移到c1内pos所指的位置之前

c.splice(pos,c2,c2pos) //将c2内c2pos所指的元素转移到c1内pos所指的位置上

c.splice(pos,c2,c2beg,c2end) //将c2内从c2beg到c2end区间内的所有元素转移到c1内pos所指的位置之前

c.sort() //以operator<为准则，对所有元素排序

c.sort(op)  //以op为准则，对所有元素排序

c.merge(c2) //假设c1和c2都包含已序元素，将c2的全部元素转移到c1.并保证合并后的list仍为已序

c.merge(c2,op) //假设c1和c2都包含op原则下已序元素，将c2的全部元素转移到c1.并保证合并后的list在op原则下仍为已序

c.reverse() //将所有元素反序
```

