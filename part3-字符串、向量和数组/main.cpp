#include <iostream>
using namespace std;

void init()
{
    string s1 = "hello";
    string s2("world");
    string s3(10, 'a');
    cout << s1 << " " << s2 << " " << s3 << endl;
}

int main()
{
    init();
    return 0;
}