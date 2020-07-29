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

int main()
{
    // priority();
    operatorTest();
    return 0;
}