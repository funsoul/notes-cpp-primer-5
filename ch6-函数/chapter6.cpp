#include <iostream>
#include "chapter6.h"
using namespace std;

void hello()
{
    cout << "helloworld" << endl;
}

void error_print()
{
#ifndef NDEBUG
    cerr << "ERROR: " << __FILE__
         << " : in function " << __func__
         << " at line " << __LINE__ << endl
         << " compiled on " __DATE__ << endl;
#endif
}