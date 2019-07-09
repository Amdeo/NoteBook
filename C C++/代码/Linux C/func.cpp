//
// Created by amdeo on 2019-07-02.
//
#include "func.h"
#include <iostream>
#include <unistd.h>
#include "common.h"
#include <unistd.h>
#include <sys/types.h>
#include <array>


void ydb::process_test()
{
    pid_t pid;
    int i = 0;
    cout<<"before fork\n";
    pid = fork();
    cout<<"after fork\n";
    if (pid < 0)
    {
        cout<< "fork failed" <<endl;
    }
    else if(pid == 0)   //子进程
    {
        while (i<10) {
            cout << "I am child,i = " << i << endl;
            i += 1;
        }
        cout << "child process is " << getpid() << endl;
    }
    else{
        //父进程
        //sleep(10);
        while (i<10){
            cout<<"I am parent,i = "<<i<<endl;
            i += 2;
        }

        cout<< "parent process is " <<getpid()<<endl;
    }
    cout<<"exit process\n";
}

void ydb::arraytest()
{
//    array<int,5> myarray = {1,2,3,4,5};
//    for(array<int,5>::iterator it = myarray.begin();it != myarray.end();++it)
//        cout<<' '<< *it;
//    cout<<"\n";

//    for(array<int,5>::reverse_iterator iter = myarray.rbegin();iter != myarray.rend();++iter)
//        cout<<' '<< *iter;
//    cout<<"\n";
//    array<int,5> myarray = {1,2,3,4,5};
//    for(array<int,5>::const_iterator it = myarray.cbegin();it != myarray.cend();++it)
//        cout<<' '<< *it;
//        cout<<"\n";

    array<int,5> myarray = {1,2,3,4,5};
    for(array<int,5>::const_reverse_iterator it = myarray.crbegin();it != myarray.crend();++it)
        cout<<' '<< *it;
    cout<<"\n";






}
