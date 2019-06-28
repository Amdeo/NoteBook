## linux 网络编程

### TCP/IP

TCP/IP是Transmission Control Protocol/Internet Protocol的简写，中文传输控制协议/因特网互联协议，又名网络通信协议，是Internet基本协议。

TCP/IP协议是为了解决不同系统的计算机之间的传输通信而提出的一个标准，不同系统的计算机采用同一种协议后，就能互相通信，从而建立网络连接，实现资源共享和网络通信。

TCP/IP协议簇按照层次由上而下可以分成4层：

1.应用层包含所以高层协议，比如虚拟终端协议、文件传输协议、电子邮件传输协议、域名服务、超文本传送协议等等，这些就是对应用户常用的应用软件。

2.传输层：这层就是TCP协议和UDP协议这层，TCP是面向连接的协议，它提供可靠的报文传输和对上层应用的连接服务，UDP协议是面向无连接的不可靠传输的协议，主要用于不需要TCP的排序和流量控制等功能的应用程序。

3.网际层，该层是整个TCP/IP体系结构的关键部分，其功能是使主机把分组发往任何网络，并使分组独立地传向目标，这些分组可能经不同的网络，到达的顺序和发送的顺序也可能不同。

4.网络接口层，或称数据链路层，该层是整个体系结构的基础部分，负责接收IP和IP数据包，通过网络向外发送，或接收处理从网络上传的物理帧，抽出IP数据包，向IP层发送。该层是主机与网络的实际连接层。


Linux网络编程是通过socket（套接字）接口实现，socket是一种文件描述符，socket起源于UNIX，在Unix一切皆文件哲学思想下，socket是以一种“打开----读/写----关闭”模式的实现，服务器和客服端各自维护一个文件，在建立连接后，可以向自己问价写入内容供对方读取或者读取对方内容，通讯结束时关闭文件。



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



服务器端编程：

（1）创建服务端套接字（使用socket）

（2）绑定套接字到一个IP地址和一个端口上（使用bind）

（3）将套接字设置为监听模式等待连接请求（使用listen），这个套接字就是监听套接字。

（4）请求到来后，接受连接请求，返回一个新的对应此次连接的套接字（accept）。

（5）用返回的新的套接字和客户端进行通信，即发送或接受数据（使用函数send或recv），通信结束就关闭这个套接字（使用closesocket）

（6）监听套接字继续处于监听状态，等待其他客户端的连接请求。

（7）如果要退出服务器程序，则先关闭监听套接字



客户端编程：

（1）创建客户端套接字（使用函数socket）

（2）向服务器发出连接请求（使用函数connect）

（3）和服务器进行通信，即发送或接收数据（使用函数send或recv）

（4）如果要关闭客户端程序，则先关闭套接字（使用函数closesocket）
