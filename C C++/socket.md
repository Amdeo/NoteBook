## linux 网络编程

Linux网络编程是通过socket（套接字）接口实现，socket是一种文件描述符，socket起源于UNIX，在Unix一切皆文件哲学思想下，socket是以一种“打开----读/写----关闭”模式的实现，服务器和客服端各自维护一个文件，在建立连接后，可以向自己问价写入内容供对方读取或者读取对方内容，通讯结束时关闭文件。



socket类型

常见的socket分为3种

1. 流式sokcet（SOCK_STREAM）

   流式套接字提供可靠的，面向连接的通信流；它使用TCP协议，从而保证了数据传输的正确性，和顺序性。

2. 数据报socket（SOCK_DGRAM）

   数据报套接字定义了一种无连接的，数据通过相互独立报文进行传输，是无序的，并且不保证是可靠、无差错的，它使用数据报协议UDP。

3. 原始socket（SOCK_RAW）

   原始套接字允许对底层协议如“IP”或“ICMP”进行直接访问，功能强大但使用较为不便，主要用于一些协议的开发。



```C++
int socket(int domain,int type,int protocol);

int bind(int sockfd,struct sockaddr * my_addr.int addrlen);

int listen(int sockfd,int backlog);

int accept(int sockfd,struct sockaddr *addr,int *addrlen);

int connect(int sockfd,struct sockaddr* serv_addr,int addrlen);

size_t write(int fd,const void *buf,size_t nbytes)

size_t read(int fd,void *buf,size_t nbyte);

int send(int sockfd,const void *msg,int len,int flags)

int recv(int sockfd,void * buf,int len,unsigned int flags);

int sendto(int sockfd,const void *msg,int len,unsigned int flags,struct sockaddr *to,int tolen)

int recvfrom(int sockfd,void *buf,int len,unsigned int flags,struct sockaddr * from,int *fromlen)


int fcntl(int fd, int cmd, long arg)
```

