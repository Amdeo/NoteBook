//
// Created by 77465 on 2019/6/15.
//
#include <iostream>

#ifndef LINUX_C_COMMON_H
#define LINUX_C_COMMON_H

using namespace std;

//打印地址
template <class T>
void print_point(T *p)
{
    cout<< static_cast<void *>(p) <<endl;
}

//打印值
template <class T>
void print_value(T value)
{
    cout<< value <<endl;
}

#endif //LINUX_C_COMMON_H
