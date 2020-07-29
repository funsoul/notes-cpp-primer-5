#include <iostream>
#include <vector>
using namespace std;

void init()
{
    string s1 = "hello";
    string s2("world");
    string s3(10, 'a');
    cout << s1 << " " << s2 << " " << s3 << endl;
}

void rangeFor()
{
    string str("hello world");
    for (auto c : str)
        cout << c << endl;
    
    for (auto &c : str)
        c = toupper(c);
    cout << str << endl;
}

void vectorTest()
{
    vector<int> v;
    for (int i = 0; i != 100; ++i)
        v.push_back(i);
    // for (int i : v)
    //     cout << i;
    
    cout << "size: " << v.size() << ", capacity: " << v.capacity() << endl;
}

int main()
{
    // init();
    // rangeFor();
    vectorTest();
    return 0;
}