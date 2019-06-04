#include <pthread.h>
#include <iostream>
#include <stdio.h>

using namespace std;

void *thfunc(void *arg)
{
    
    int *pn = (int*)(arg);
    int n = *pn;

    cout<<"线程1的参数："<< n << endl;
    return (void *)0;
    
}

void *thfunc1(void * arg)
{
    char * str = (char *)(arg);

    cout<<"线程2的参数："<<str <<endl;

    return (void*)0;
}

int main()
{
    pthread_t tidp;
    pthread_t tidp1;

    int n = 1;
    int ret = pthread_create(&tidp,NULL,thfunc,&n);

    if(ret)
    {
        cout<< "pthread_create failed:%d\n" <<endl;
        return -1;
    }

    pthread_join(tidp,NULL); //等待线程结束

    const char * str = "yuandongbin";

    int ret1 = pthread_create(&tidp1,NULL,thfunc1,(void *)str);

    if(ret1)
    {
        cout<< "pthread_create failed:%d\n" <<endl;
        return -1;
    }

    pthread_join(tidp1,NULL); //等待线程结束

    cout<<"主线程结束"<<endl;
    return 0;
}