# shell实战

**shell脚本开头**

指定一个解释器

以#！开头 + 解释器的路径

```shell
#! /bin/bash
```

shell脚本的执行方法

第一种方法：

使用sh命令 + 脚本路径

```shell
 sh script.sh
```

第二种方法

```
1. 赋予shell脚本权限
chmod a+x script.sh

2. 执行
./script.sh
```

# 打印

**echo**

使用echo打印，每次代用会默认添加一个换行符

```shell
#输出双引号的字符串
echo "Welcome to Bash"

#输出不带双引号的文本
echo Welcome to Bash

#输出单引号的文本
echo 'Welcome to Bash'
```

**printf**

```shell
#! /bin/bash

printf "Hello world\n"

printf "%-5s %-10s %-4s\n" NO Name Mark
# “-” 指明一个格式为左对齐（默认的使用右对齐方式）
# 5s 指定一个字符串长度，不够的添加空格
```

-  使用printf不会添加换行符，需要换行需要自己增加



# 变量

**定义变量**

```shell
#定义变量 = 左右两边不能有空格
fruit=apple 
count=5
```

**使用变量**

- $变量名

- ${变量名}

```shell
echo "We have $count ${fruit}(s)"
```



```shell
#! /bin/bash

fruit=apple
count=5
#变量的使用
echo "We have $count ${fruit}(s)"

#output
#We have 5 apple(s)
#
```

# **获取变量的长度**

```shell
var=0123456789
length=${#var}

#output : 10
```

# **获取当前shell的版本**

```
echo $SHELL
或者
echo $0
```

# 判断当前的用户是为超级用户

使用$UID这个变量，因为root用户的UID是0

```shell
if [$UID -ne 0];then
echo Non root user.Please run as root.
else
echo "Root user"
fi
```

# 通过shell进行数学运算

let命令可以直接执行基本的算数操作

```shell
#! /bin/bash
no1=4;
no2=5;

let result=no1+no2;
echo $result

#output：9
```

自增和自减

```
let no1++
let no1--
```

简写

```
let no+=6   #等价于 let no=no+6
```

使用操作符[]的使用方法和let命令类似：

```shell
#! /bin/bash
no1=4;
no2=5;

result=$[no1 + no2]

result=$[$no1 + 5]

result=$((no1 + 50))

result=`expr 3 + 4`

#这些方法只能用于整数运算，而不支持浮点数
```

## 浮点数运算

bc是一个用于数学运算的高级工具，这个精密计算器包含了大量的选项

```shell
echo "4 * 0.56" | bc  #2.24

no=54;
result=`echo "$no * 1.5" | bc`
echo $result

#ourput 81.0
```

- 设定小数精度（数值范围）：在下面的例子中，参数scale=2将小数位个数设置为2

```shell
echo "scale=2;3/8" | bc
#output 0.37
```

参数scale=2将小数位个数设置为2

- 进制转换：用bc可以将一种进制系统转换为另一种，来看看如何将十进制转换成二进制，然后再将二进制转换回十进制：

```shell
#! /bin/bash
no=100
echo "obase=2;$no" | bc

no=1100100
echo "obase=10;ibase=2;$no" | bc
```

obase=2 二进制 obase=10 十进制

## 计算平方以及平方根：

```shell
echo "sqrt(100)" | bc #Square root
echo "10^10" | bc #Square
```



# 输出重定向

```shell
echo "This is a sample text 1" > temp.txt
```

- 先清空temp.txt文件内容
- 将“This is  a sample text 1” 写入文件

```shell
echo "This is a sample text 2" >> temp.txt
```

将输出的内容以追加的方式写入文件中。

# 数组和关联数组

定义一个数组

```shell
array_var=(1 2 3 4 5 6)
```

数组赋值

```
array_var[0]="test1"
array_var[1]="test2"
array_var[2]="test3"
array_var[3]="test4"
array_var[4]="test5"
array_var[5]="test6"

echo ${array_var[0]}
```

获取所有的数组元素

```
array_var[*]
```

# 获取、设置日期和延时

```shell
date
#output: Thu Aug  1 09:50:07  2019
```

获取秒数

```shell
date +%s
#output: 1564653113
```

获取星期

```shell
date +%A #output: Sat
date +%a #output: Saturday
```

获取月

```shell
date +%B #output: Nov
date +%b #output: November
```

获取日

```shell
date +%d #output：01
```

固定日期格式

```shell
date +"%Y%m%d%H%M%S" #output: 20190801192735

date +"%Y %m %d %H %M %S" #output: 2019 08 01 19 28 35

date +"%d %B %Y" #output:01 August 2019
```

# 函数和参数

```shell
function fname()
{
statements;
}

或者
fname()
{
statements;
}

```

```shell
fname()
{
	echo $1,$2;  #访问参数1和参数2
	echo "$@";   #以列表的方式一次性打印所有参数
	echo "$*";	 #类似于$@,但是参数被作为实体
	return 0;    #返回值
}
```

# 循环

## for循环

```shell
for i in $list;
do 
	actions;
done
#或者
for((i=0;i<10;i++))
{
	commands;
}
```

## while循环

用true作为循环条件能够产生无限循环。

```shell
while condition
do
	conmmands;
done
```

## until循环

它的功能是一直执行循环知道给定的条件为真

```shell
x=0;
until [$x -eq 9]; # [$x -eq 9] is the condition
do let x++;echo $x;
done
```

# 比较

| 参数 | 说明           |
| ---- | -------------- |
| -eq  | 等于则为真     |
| -ne  | 不等于则为真   |
| -gt  | 大于则为真     |
| -ge  | 大于则为真     |
| -lt  | 小于则为真     |
| -le  | 小于等于则为真 |

- [-f $file_var] : 如果给定的变量包含正常的文件路径或文件名，则返回真。
- [-x $var] : 如果给定的变量包含的文件可执行，则返回真
- [-d $var] : 如果给定的变量包含的是目录，则返回真
- [-e $var] : 如果给定的变量包含的文件存在，则返回真
- [-c $var] : 如果给定的变量包含的是一个字符设备文件的路径，则返回真
- [-b $var] : 如果给定的变量包含的是一个块设备的路径，则返回真
- [-w $var] :如果给定的变量包含的文件可写，则返回真
- [-r $var] : 如果给定的变量包含的文件可读，则返回真
- [-L $var] : 如果给定的变量包含的是一个符号链接，则返回真



## 字符串比较

使用字符串比较时，最好用双中括号，因为有时候采用单个中括号会产生错误，所以最好避开它们。

可以检查两个字符串

- `[[ $str1 = $str2]]` : 当str1等于str2时，返回真，也就是说，str1和str2包含的文本是一模一样。
- `[[ $str1 == $str2]]`：这是检查字符串是否相等的另一种写法，也可以检查两个字符串是否不同。
- `[[ $str1 ！= $str2]]`：这是str1和str2不相同，则返回真。
- `[[$str1 > $str2]]`: 如果str1的字母序比str2大，则返回真
- `[[$str1 < $str2]]`: 如果str1的字母序比str2小，则返回真
- `[[-z $str1]]`: 如果str1包含的是空字符串，则返回真
- `[[-n $str1]]`: 如果str1包含的是非空字符串，则返回真

# cat 命令

1.压缩空白行

文本中有多个空行需要被压缩成单个

```shell
cat -s file 
```

2.将制表符显式^|

```shell
cat -T file.py
```

3.显示行号

```shell
cat -n lines.txt
```

# 文件查找与文件列表find

find命令的工作方式如下：沿着文件层次结构向下遍历，匹配符合条件的文件，并执行相应的操作。

要列出当前目录及子目录下所有的文件和文件夹，

```
find base_path
```

bash_path可以是任何位置，find会从改位置开始向下查找。

```shell
find . -print
#打印文件和目录的列表
```

. 指定当前目录， .. 指定父目录。

- -print指明打印出匹配文件的文件名（路径）。当使用-print时，’\n'作为用于分隔文件的定界符。
- -print0指明使用’\0’作为定界符来打印每一个匹配的文件名，当文件名中包含换行符时

**根据文件名或正则表达式匹配搜索**

```shell
find . -name ".txt" -print
#查找当前目录中所有的txt文件
```

匹配多个条件

```sh
find . \( -name "*.txt" -o -name "*.pdf" \) -print
#查找当前目录中所有txt和pdf文件
```

-iregex用于忽略正则表达式的大小写

```shell
find . -iregex ".*\(\.py\|\.sh\)$"

#搜索py（无视大小写）和sh（无视大小写）的后缀的文件，
```

否定参数

```shell
find . ! -name ".txt" -print
#查找除了txt之外的文件
```

目录深度搜索

- mindepth 最小深度
- maxdepth 最大深度

```shell
find . -mindepth 2 *
```

根据文件类型搜索

linux文件类型包括普通文件、目录、字符设备、块设备、符号链接、硬链接、套接字以及FIFO

-type可以对文件搜索进行过滤

```shell
find . -type d -print
```

根据文件时间进行搜索

- 访问时间（-atime）：用户最近一次访问文件的时间
- 修改时间（-mtime）：文件内容最后一次被修改的时间
- 变化时间（-ctime）：文件元数据最后一次改变的时间

```shell
#打印出在最近七天被访问过的所有文件：
find . -type f -atime -7 -print
#打印出在七天前被访问过的所有文件：
find . -type f -atime 7 -print
#打印出访问时间超过七天的所有文件:
find . -type f -atime +7 -print
```

按分钟作为计量单位的

- -amin(访问时间)
- -mmin（修改时间）
- -cmin（变化时间）

```shell
#打印出访问时间超过7分钟的所有文件
find . -type f -amin +7 -print
```

-newer参数

```shell
#查找比参考文件更新的所有文件
find . -type -newer file.txt -print
```

基于文件大小的搜索

```shell
find . -type f -size +2k
#大于2KB的文件
```

```shell
find . -type f -size -2k
#小于2kb的文件
```

```shell
find . -type f -size 2k
#大于等于2kB的文件
```

-delete可用来删除find查找的匹配文件

```shell
#删除当前目录下所有的.swp文件
find . -type f -name "*.swp" -delete
```

```shell
#打印出权限为644的文件
find . -type f -perm 644 -print
```

```shell
#打印出用户slynux拥有的所有文件
find . -type f -user alynux -print
```

 结合find执行命令或动作

```shell
find . -type f -user root -exec chown slynux{} \;
```

# xargs命令

xargs命令把从stdin接收到的数据重新格式化，再将其作为参数提供给其他命令

将多行输入转换成单行输出

```shell
cat example.txt | xarga #将输出的文件内容，输出内容转换为一行
```

将单行输入转换成多行输出

```shell
cat example.txt | xargs -n 3 #将输出的文件内容，输出内容转换为一行(按照空格为定界符)
```

使用-d选项为输入指定一个定制的定界符

```shell
echo "splitXsplitXsplitXsplitXsplit" | xargs -d X
#output: split split split split
```

```shell
echo "splitXsplitXsplitXsplitXsplit" | xargs -d X -n 2
#output:
#split split
#split split
```

# 校验与核实

111



















































