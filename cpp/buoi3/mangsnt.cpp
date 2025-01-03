#include <iostream>
#include <math.h>
using namespace std;

bool kiemtrasnt(int n)
{
    if (n < 2)
        return false;

    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    };
    return true;
}

int main()
{
    int n;
    int a[20];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "nhap a: " << i << " ";
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        bool n = kiemtrasnt(a[i]);
        if (n)
        {
            cout << a[i] << " la snt" << endl;
        }
        else
        {
            cout << a[i] << " khong la snt" << endl;
        }
    }
}