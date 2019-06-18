一、SQL基础
===

模式定义了数据如何存储、存储什么样的数据以及数据如何分解等信息，数据库和表都有模式。

主键的值不允许修改，也不允许复用（不能将已经删除的主键值赋给新数据行的主键）。

SQL（Structured Query Language)，标准 SQL 由 ANSI 标准委员会管理，从而称为 ANSI SQL。各个 DBMS 都有自己的实现，如 PL/SQL、Transact-SQL 等。

SQL 语句不区分大小写，但是数据库表名、列名和值是否区分依赖于具体的 DBMS 以及配置。

SQL 支持以下三种注释：

```sql
# 注释
SELECT *
FROM mytable; -- 注释
/* 注释1
   注释2 *
```



二、创建数据库和表
===

数据库

```
create database database_name;
```

表

```sql
CREATE TABLE mytable (
  # int 类型，不为空，自增
  id INT NOT NULL AUTO_INCREMENT,
  # int 类型，不可为空，默认值为 1，不为空
  col1 INT NOT NULL DEFAULT 1,
  # 变长字符串类型，最长为 45 个字符，可以为空
  col2 VARCHAR(45) NULL,
  # 日期类型，可为空
  col3 DATE NULL,
  # 设置主键为 id
  PRIMARY KEY (`id`));
```



三、修改表
===

**增加表字段**

```sql
alter table tabe_name add col_name datatype;
```

**删除表字段**

```sql
alter table table_name drop column_name datatype；
```

**删除表**

```sql
drop table table_name;
```

**删除数据库**

```sql
drop database database_name;
```

**删除索引**

```sql
alter table table_name drop index index_name;
```



四、插入
===

**普通插入**

```sql
insert into table_name(field1,field) values(val1,val2);
```

**插入检索出来的数据**

```sql
# 方法一
INSERT INTO mytable1(col1, col2)
SELECT col1, col2
FROM mytable2;
```

**将一个表的内容插入到一个新表**

```sql
CREATE TABLE newtable AS
SELECT * FROM mytable;
```

**创建表备份**

SELECT INTO 语句从一个表中选取数据，然后把数据插入另一个表中。

```sql
select column_name(s) into new_table_name from old_tablename;
```

五、更新
===

```sql
update table_name set col = val where condition;
```

六、删除
===

```sql
delete from table_name where condition;
```

七、查询
===

**获取表中全部数据**

```sql
select * from table_name where condition;
```

**获取指定列数据**

```sql
select column(s) from table_name where condition;
```

**获取指定列排序的数据**

```sql
select column(s) from table_name where condition order by column; --按照column(默认升序)

--ASC ：升序（默认）DESC ：降序 使用方法 order by column (ASC 或者 DESC)

```

**获取数据指定条数**

mysql:

```sql
select column(s) from table_name where condition limit 3; -- 获取前3条数据

select column(s) from table_name where condition limit 3-2; -- 获取第4条、5条数据
```

oracle:

```sql
select column(s) from table_name where condition rownum <= number;
```

**获取不重复的值**

相同值只会出现一次。它作用于所有列，也就是说所有列的值都相同才算相同。

```sql
select distinct column(s) from table_name where condition;
```







# 八、条件

**模糊匹配like：**

```sql
select * from table_name where column like pattern;
-- pattern %xx  %xx%  xx%

select * from table_name where column like '_xxx' -- '_'替换一个字符

select * from table_name where column like '[abc]xxx'
--条件可以看作axxx bxxx cxxx 即[abc] 指列表中的任意字符
--[^abc]和[!abc]非abc中任一字符
```

IN操作符

```sql
select * from table_name where column in (val1,val2,val3);
```

between操作符

```sql
select * from table_name where column between val1 and val2; --val1和val2之间
```















