
### 变量赋值 ###
增量赋值：

`x += 1` -> `x = x + 1`

多重赋值：

`x = y = z = 1`

多元赋值：

`x, y, z = 1, 2, 'a string'`


### for循环的内建函数range ###

```shell
for item in range(1,4):
	print(item)

结果：
1
2
3

下面我们打印下这个函数
print(range(3))

结果：
range(0, 3)
```


- 一个参数，range(n),即从0~n-1

- 两个参数，range(n,m), 即遍历的范围从n~m-1


### 对象身份比较符 ###

`a is b` 

判断a 和 b是否是一个对象

`a is not b`

判断a 和 b不是一个对象

### type()和isinstance() ###

- type(),判断变量的类型


### 多元赋值

`x,y,z = 1,2,'string'`

