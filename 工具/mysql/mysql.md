
### 启动mysql


```
service mysqld start
或者 systemctl start mysqld.service
```


### 停止mysql服务
```
service mysqld start
或者
systemctl stop mysqld.service
```
### 初始化root密码

```
mysqladmin -u root password '密码'
```

### 登入mysql


```
mysql -u root -p
```


### 新建用户：
```
GRANT SELECT,INSERT,UPDATE,DELETE,CREATE,DROP
     ON TUTORIALS.*
     TO 'GenlUser'@'localhost'
     IDENTIFIED BY 'u1234%';
```


### 修改用户密码
- 使用root用户连接mysql,`要知道修改密码只有root用户有权限`
```
     use mysql //切换数据库
 
 
    ##设置root用户对外密码
    SET PASSWORD FOR 'root'@'%' = PASSWORD('root@123');
 
    flush privileges; //提交语句
 
```

### 创建数据库：

#### 在mysql中创建数据库

```
CREATE DATABASE 数据库名;
 
创建数据库设置字符集
CREATE DATABASE IF NOT EXISTS 数据库名 DEFAULT CHARSET utf8mb4 COLLATE utf8mb4_unicode_ci;
```

#### 使用 mysqladmin 创建数据库

```
[root@host]# mysqladmin -u root -p create RUNOOB
```

### 字符集设置

查看修改数据库字符集编码

```
mysql> show variables like "char%";
mysql> show variables like "collation%";
mysql> set character_set_server=utf8;
mysql> set collation_server=utf8_general_ci;
```

- 查看database的字符编码

```
show create database 数据库名;
```

- 查看table的字符编码

```
show create table 表名;
```

- 查看column的字符编码

```
show full columns from 表名;
```

 

修改数据表字符集编码

```
mysql> alter table xxx default character set utf8 collate utf8_general_ci;
```

或

```
ALTER DATABASE database_name CHARACTER SET = utf8mb4 COLLATE = utf8mb4_unicode_ci
```

 

### 删除数据库

```
drop database <数据库名>;
```

### 选择数据库

```
use 数据库名
```

 

 

#### MySQL的命令

```
SHOW DATABASES:
列出 MySQL 数据库管理系统的数据库列表。
 
SHOW TABLES:
显示指定数据库的所有表，使用该命令前需要使用 use 命令来选择要操作的数据库。
 
SHOW COLUMNS FROM 数据表:
显示数据表的属性，属性类型，主键信息 ，是否为 NULL，默认值等其他信息。
 
SHOW INDEX FROM 数据表:
显示数据表的详细索引信息，包括PRIMARY KEY（主键）。
 
SHOW TABLE STATUS LIKE [FROM db_name] [LIKE 'pattern'] \G:
该命令将输出Mysql数据库管理系统的性能及统计信息。
```

 

#### 导出数据

```
mysqldump -u root -p database_name table_name > dump.txt
```

 

导入数据

```
#登入mysql
mysql -u root -p
 
#创建数据库
create database admin
 
#导入数据
source 文件
```

或

```
$ mysqlimport -u root -p --local 数据库名 文件名
```