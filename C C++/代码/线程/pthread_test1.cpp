#include <pthread.h>
#include <iostream>
#include <unistd.h>

using namespace std;

void *func(void * arg)
{
    cout<<"I am child thread"<<endl;
}


int main()
{
    //
    pthread_t tidp;
    int ret;

    ret = pthread_create(&tidp,NULL,func,NULL);

    if (ret)
    {
        cout <<"pthread create failed:"<< ret <<endl;
    }
    //sleep(1);

    cout<<"in main:thread "<<endl;

    return 0;

}