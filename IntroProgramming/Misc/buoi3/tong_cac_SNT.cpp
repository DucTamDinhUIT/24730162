#include <iostream>
#include <math.h>
using namespace std;

bool boolSNT(int a)
{
    if (a < 2)
        return false;
    for (int i = 2; i <= sqrt(a); i++)
    {
        if (a % i == 0)
        {
            return false;
        }
    }

    return true;
}
int main()
{
    int so, tong;
    cin >> so;
    tong = 0;
    for (int i = 0; i <= so; i++)
    {
        if (boolSNT(i))
        {
            tong += i;
        }
    }
    cout << tong;
}