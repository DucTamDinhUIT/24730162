#include <iostream>
using namespace std;
int main()
{
    int a[50];
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        cout << "nhap so thu " << i << ": ";
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << "a" << i << " : ";
        cout << a[i] << endl;
    }

    
}