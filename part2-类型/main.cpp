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

void decltype_test()
{
    int a = 3, b = 4;
    decltype(a) c = a;
    decltype((b)) d = a;
    ++c;
    ++d;
    printf("c: %d, d: %d\n", c, d);
}

int main()
{
    // ref_test();
    // pointer_test();
    decltype_test();
    return 0;
}

