#include <iostream>
#include <vector>
#include "chapter6.h"
using namespace std;

void swap(int *i, int *j)
{
    int tmp = *i;
    *i = *j;
    *j = tmp;
}

void swap(int &i, int &j)
{
    int tmp = i;
    i = j;
    j = tmp;
}

void testSwap()
{
    int i = 1, j = 2;
    swap(i, j);
    cout << "i: " << i << ", j: " << j << endl;
}

char &get_val(string &str, string::size_type ix)
{
    return str[ix];
}

void testGetVal()
{
    string str("hello");
    get_val(str, 0) = 'A';
    cout << str << endl;
}

vector<string> getList()
{
    return {"aa", "bb", "cc", "dd", "ee"};
}

void testGetList()
{
    vector<string> list = getList();
    for (auto str : list) {
        cout << str << endl;
    }
}

// test6_40()
int ff(int a, int b = 1, int c = 2, int d = 3);
// char *init(int ht = 24, int wd, char c); // error

int main()
{
    // hello();
    // testSwap();
    // testGetVal();
    // testGetList();
    error_print();
    return EXIT_SUCCESS;
}