#include <iostream>
using namespace std;

void twoSum(int a, int b)
{
    cout << "enter two numbers" << endl;

    int number1, number2;

    cin >> number1 >> number2;

    cout << "sum: " << number1 + number2 << endl;
}

void multiplySum()
{
    int sum = 0, value = 0;
    
    while (cin >> value) {
        sum += value;
    }

    cout << "sum: " << sum << endl;
}

void variable()
{
    unsigned u = 10;
    int i = -42;
    cout << u + i << endl;
}

int main()
{
    // twoSum(1, 2);
    // multiplySum();
    // variable();
    return 0;
}

