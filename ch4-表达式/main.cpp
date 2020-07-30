#include <iostream>

using namespace std;

void priority()
{
    cout << 5 + 10 * 20 / 2 << endl;

    int i = 0;
    cout << i << " " << ++i << endl;
}

void operatorTest()
{
    int i = 1024;
    int j = -i;
    bool ok = true;
    bool ok2 = -ok;

    cout << i << " " << j << " " << ok << " " << ok2 << endl;
}

void wrapArround()
{
    short i = 32767;
    i += 1;
    cout << i << endl; // -32768
}

int main()
{
    // priority();
    // operatorTest();
    wrapArround();
    return 0;
}