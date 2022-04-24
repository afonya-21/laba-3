#include <iostream>
#include "String.h"
#include <locale.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    int b = 0;
    TString s("abcdef");
    int* a;
    a = s.CharPositions("b", b);
    for (int i = 0; i < b; i++)
    {
        cout << a[i] << endl;
    }

    return 0;
}