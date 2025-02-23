#include <iostream>

using namespace std;

int main()
{
    int a[50];
    int len;
    cin >> len;
    for (int i = 0; i < len; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < len; i++)
    {
        cout << "a" << i << ": " << a[i] << endl;
    }

    int b[len];
    int j = 0;
    for (int i = len -1 ; i >= 0; i--)
    {
        b[j] = a[i];
        cout << "j = " << j << endl;
        j++;
    }

    for (int i = 0; i < len; i++)
    {
        cout << b[i] << " ";
    }
}