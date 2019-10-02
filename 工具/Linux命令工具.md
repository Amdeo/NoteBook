# SFTP

## 登入

（1）sftp xxx.xxx.xxx.xxx 登入（默认root用户），若指定用户sftp username@xxx.xxx.xxx.xxx 进行登录

（2）登入成功后，会提示输入密码

（3）进入目录，ls查看目录下内容

（4）cd切换目录，get获取文件，put上传文件

（5）quit / bye / exit 退出sftp

## 常用命令

```
ls 查看当前目录下文件
help 查看sftp支持哪些命令
cd 指定目录
pwd 查看当前目录
get xxx.txt 下载xxx文件
put xxx.txt 上传文件
```



# ssh

**centos**

安装

```
yum install openssh-server
```

开启sshd服务

```
sudo service sshd start
```

检查  sshd  服务是否已经开启，输入

```
ps -e | grep sshd
```

检查  **22** 号端口是否开启监听

```
netstat -an | grep 22
```

