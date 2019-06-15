#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include "common.h"

using namespace std;

int main() {
    int a[] = {1,2,3,4,5};
    print_point(a);
    cout<< *a+1 <<endl;
    print_point(a+1);
    print_point(&a);
    print_point(&a+1);
    return 0;
}