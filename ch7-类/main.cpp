#include <iostream>
using namespace std;

class Test
{
private:
    string name = "hello";
public:
    void hello()
    {
        cout << name << endl;
    }
};

int main()
{
    Test test = new Test();
    test.hello();
    return 0;
}