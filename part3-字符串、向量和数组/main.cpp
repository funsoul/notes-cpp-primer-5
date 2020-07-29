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

void it()
{
    string s("hello world");
    if (s.begin() != s.end()) {
        auto it = s.begin();
        *it = toupper(*it);
    }
    cout << s << endl;

    for (auto it = s.begin(); it != s.end() && !isspace(*it); it++)
        *it = toupper(*it);
    cout << s << endl;
}

void itArr()
{
    int a[] = {1,2,3};
    int *b = begin(a);
    int *e = end(a);
    for (;b != e;b++)
        cout << *b << endl;
}

void pointer()
{
    int a[] = {1,2,3};
    int *p = &a[2];
    cout << *p << endl;     // 3
    cout << p[-2] << endl;  // 1
}

void multiplyArr()
{
    int a[3][4] = {0};

    for (auto &row: a) {
        for (auto col: row) {
            cout << col << endl;
        }
    }
}

int main()
{
    // init();
    // rangeFor();
    // vectorTest();
    // it();
    // itArr();
    // pointer();
    multiplyArr();
    return 0;
}