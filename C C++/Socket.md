## linux 网络编程

### TCP/IP

TCP/IP是Transmission Control Protocol/Internet Protocol的简写，中文传输控制协议/因特网互联协议，又名网络通信协议，是Internet基本协议。

TCP/IP协议是为了解决不同系统的计算机之间的传输通信而提出的一个标准，不同系统的计算机采用同一种协议后，就能互相通信，从而建立网络连接，实现资源共享和网络通信。

TCP/IP协议簇按照层次由上而下可以分成4层：

**应用层**：包含所以高层协议，比如虚拟终端协议、文件传输协议、电子邮件传输协议、域名服务、超文本传送协议等等，这些就是对应用户常用的应用软件。

**传输层**：这层就是TCP协议和UDP协议这层，TCP是面向连接的协议，它提供可靠的报文传输和对上层应用的连接服务，UDP协议是面向无连接的不可靠传输的协议，主要用于不需要TCP的排序和流量控制等功能的应用程序。

**网络层**： 网络层实现数据包的选路和转发，通常使用众多分级的路由器来连接分散的主机或LAN， 该层是整个TCP/IP体系结构的关键部分，其功能是使主机把分组发往任何网络，并使分组独立地传向目标，这些分组可能经不同的网络，到达的顺序和发送的顺序也可能不同，协议包括IP协议、ICMP协议，IP协议。IP协议根据数据包的目的地址来决定如何投递它。ICMP协议（因特网控制报文协议），主要用于检测网络连接

**网络接口层** : 或称数据链路层，该层是整个体系结构的基础部分，负责接收IP和IP数据包，通过网络向外发送，或接收处理从网络上传的物理帧，抽出IP数据包，向IP层发送。该层是主机与网络的实际连接层。数据链路层两个常用的协议是`ARP协议（地址解析协议）和RARP协议（逆地址解析协议）`，**它实现了IP地址和实际物理地址的之间的相互转换。**

**封装**

上层协议是如何使用下层协议提供的服务的呢？其实这是通过封装实现的，应用程序数据在发送到物理网络之前，需要经过传输层 ---> 网络层  ----> 链路层，每一层的协议都将在上层数据的基础上加上自己的头部信息，以实现改层的功能，这个过程就叫封装

|        |            |        |             |              |
| ------ | ---------- | ------ | ----------- | ------------ |
| 应用层 |            |        |             | 应用程序数据 |
| 传输层 |            |        | TCP/UDP头部 | 应用程序数据 |
| 网络层 |            | IP头部 | TCP/UDP头部 | 应用程序数据 |
| 链路层 | 以太网头部 | IP头部 | TCP/UDP头部 | 应用程序数据 |

#### ARP协议工作原理

ARP协议能实现任意网络层地址到任意物理地址的转换，其工作原理是：主机向自己的网络广播一个ARP请求，该请求包含目标机器的网络地址，此网络上的其他机器都将收到这个请求，但只有被请求的目标机器会回应一个ARP应答，其中包含自己的物理地址。

#### DNS工作原理

我们通常使用机器的域名来访问这台机器，而不直接使用其IP地址，比如访问网站，那么如何将机器的域名转换成IP地址，这就需要使用域名查询服务，就是使用DNS协议向DNS服务器查询目标主机的IP地址。

需要访问DNS服务器，就需要知道DNS服务器的IP地址。我们需要配置DNS服务器的IP地址，常用有114.114.114.114 或者 8.8.8.8 。linux机器可以在/etc/resolv.conf文件中增加IP地址，可以配置两条IP地址（首选DNS服务器地址和备选DNS服务器地址）



### TCP协议详解

TCP传输是可靠的，首先，TCP协议采用发送应答机制，即发送端发送的每个TCP报文段搜必须得到接收方的应答，才认为这个TCP报文段传输成功，其次，TCP协议采用超时重传机制，发送端在发送一个TCP报文之后启动定时器，如果在定时时间内未收到应答，它将重发该报文段，最后，因为TCP报文段最终是以IP数据报发送的，而IP数据报到达接收端可能乱序、重复，所有TCP协议还会对接收到的TCP报文段重排、整理，再交付给应用层。



Linux网络编程是通过socket（套接字）接口实现，socket是一种文件描述符，socket起源于UNIX，在Unix一切皆文件哲学思想下，socket是以一种“打开----读/写----关闭”模式的实现，服务器和客服端各自维护一个文件，在建立连接后，可以向自己文件写入内容供对方读取或者读取对方内容，通讯结束时关闭文件。



**通用socket地址**

```C++
#include <bits/socket.h>
struct sockaddr
{
    sa_family_t sa_family;
    char sa_data[14];
}
```

**sa_family** 成员是地址族类型（sa_family_t）的变量。地址族类型通常与协议族类型对应。

|  协议族  |  地址族  |       描述       |
| :------: | :------: | :--------------: |
| PE_UNIX  | AF_UNIX  | UNIX本地域协议族 |
| PE_INET  | AF_INET  |  TCP/IPv4协议族  |
| PF_INET6 | AF_INET6 |  TCP/IPv6协议族  |

宏PE_ * 和 AF_ *  都定义在bits/socket.h 头文件中，两者的值一样的，所以二者通常混用

**sa_data** 成员用于存放socket地址值

| 协议族   | 地址值含义和长度                                             |
| -------- | ------------------------------------------------------------ |
| PF_UNIX  | 文件的路径名，长度可达到108字节                              |
| PF_INET  | 16bit端口号和32bit IPv4地址，共6字节                         |
| PE_INET6 | 16bit端口号，32bit流标识，128bit IPv6地址，32bit 范围ID，共26字节。 |

由于原来的结构体中 sa_data根本**无法完全容纳多数协议族的地址值**。

**新的通用socket地址结构体：**

```C++
#include <bits/socket.h>
struct sockaddr_storage
{
    sa_family_t sa_family;
    unsigned long int __ss_align;
    char __ss_padding[128-sizeof(__ss_ailgn)];
}
```

**专用socket地址**

由于之前两个socket地址结构体，操作起来很麻烦，所以linux为各个协议族提供了专门的socket地址结构体。

```C++
#include <sys/un.h>
struct sockaddr_un
{
    sa_family_t sin_family;		/*地址族：AF_UNIX*/
    char sun_path[108];			/*文件路径名*/
}

struct sockaddr_in
{
    sa_family_t sin_family;		/*地址族：AF_INET*/
    u_int16_t sin_port;			/*端口号，要用网络字节序表示*/
    struct in_addr sin_addr;	/*IPv4 地址结构体*/
}；

struct in_addr
{
    u_int32_t s_addr;			/*IPv4 地址，要用网络字节序表示*/
}；

struct sockaddr_in6
{
    sa_family_t sin6_family;	/*地址族：AF_INET6*/
    u_int16_t sin6_port;	    /*端口号，要用网络字节序表示*/
    u_int32_t sin6_flowinfo;	/*流信息，应设置为0*/
    struct in6_addr sin6_addr;	/*IPv6 地址结构体*/
    u_int32_t sin6_scope_id;	/*scope ID，尚处于实验阶段*/
}

struct in6_addr
{
    unsigned char sa_addr[16];	/*IPv6 地址，要用网络字节序表示*/
}
```

**socket类型**

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

**服务器端编程：**

（1）创建服务端套接字（使用socket）

（2）绑定套接字到一个IP地址和一个端口上（使用bind）

（3）将套接字设置为监听模式等待连接请求（使用listen），这个套接字就是监听套接字。

（4）请求到来后，接受连接请求，返回一个新的对应此次连接的套接字（accept）。

（5）用返回的新的套接字和客户端进行通信，即发送或接受数据（使用函数send或recv），通信结束就关闭这个套接字（使用closesocket）

（6）监听套接字继续处于监听状态，等待其他客户端的连接请求。

（7）如果要退出服务器程序，则先关闭监听套接字

**客户端编程：**

（1）创建客户端套接字（使用函数socket）

（2）向服务器发出连接请求（使用函数connect）

（3）和服务器进行通信，即发送或接收数据（使用函数send或recv）

（4）如果要关闭客户端程序，则先关闭套接字（使用函数closesocket）







