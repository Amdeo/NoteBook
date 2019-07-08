## vector

vector 是表示可以改变大小的数组的序列容器。

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