## map

map 是关联容器，按照特定顺序存储由 key value (键值) 和 mapped value (映射值) 组合形成的元素。

| 方法        | 含义                                                         |
| ----------- | ------------------------------------------------------------ |
| map         | 构造函数                                                     |
| begin       | 返回引用容器中第一个元素的迭代器                             |
| key_comp    | 返回容器用于比较键的比较对象的副本                           |
| value_comp  | 返回可用于比较两个元素的比较对象，以获取第一个元素的键是否在第二个元素之前 |
| find        | 在容器中搜索具有等于 k（参数）的键的元素，如果找到则返回一个迭代器，否则返回 map::end 的迭代器 |
| count       | 在容器中搜索具有等于 k（参数）的键的元素，并返回匹配的数量   |
| lower_bound | 返回一个非递减序列 `[first, last)`（参数）中的第一个大于等于值 val（参数）的位置的迭代器 |
| upper_bound | 返回一个非递减序列 `[first, last)`（参数）中第一个大于 val（参数）的位置的迭代器 |
| equal_range | 获取相同元素的范围，返回包含容器中所有具有与 k（参数）等价的键的元素的范围边界（`pair< map<char,int>::iterator, map<char,int>::iterator >`） |