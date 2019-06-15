//
// Created by 77465 on 2019/6/15.
//
#include <iostream>

#ifndef LINUX_C_COMMON_H
#define LINUX_C_COMMON_H

using namespace std;

template <class T>
void print_point(T *p)
{
    cout<< static_cast<void *>(p) <<endl;
}

#endif //LINUX_C_COMMON_H
