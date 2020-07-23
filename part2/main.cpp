#include <iostream>
using namespace std;

void ref_test()
{
    int i, &ri = i;
    i = 5; ri = 10;
    cout << i << " " << ri << endl;
}

void pointer_test()
{
    int i = 42;
    int *pi = &i;
    cout << *pi * *pi << endl;
}

int main()
{
    // ref_test();
    // pointer_test();
    return 0;
}

