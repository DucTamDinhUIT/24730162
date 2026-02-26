#include <iostream>

using namespace std;

int main()
{
    int a[50];
    int len = 5;
    for (int i = 0; i < len; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < len; i++)
    {
        cout << "a" << i << ": " << a[i] << endl;
    }
    int max, min;
    max = a[0];
    min = a[0];
    for (int i = 1; i < len; i++)
    {
        if (a[i] >= max)
        {
            max = a[i];
        }
        if (a[i] <= min)
        {
            min = a[i];
        }
    }
    cout << "max: " << max << endl;
    cout << "min: " << min << endl;
}