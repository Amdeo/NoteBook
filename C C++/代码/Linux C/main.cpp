#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include "common.h"

using namespace std;

int main() {
//    int a[] = {1,2,3,4,5};
//    print_point(a);
//    print_point(a+1);
//    print_point(&a);
//    print_point(&a+1);

    int a[][3]={1,2,3,4,5,6,7,8,9};
    print_point(a);
    print_point(a[0]);

    print_point(a+1);
    print_point(*(a+1));
    print_point(a[1]);
    print_point(a[1]+1);
    print_value(*(a[1]+1));
    print_value(*(*(a+1)+1));

    print_point(a+2);
    print_point(a[2]);

    print_point(&a);
    print_point(&a+1);



    print_value(*(a[0]));
    print_value(*(a[1]));
    return 0;
}