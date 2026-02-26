#include <iostream>
using namespace std;
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    for (int i = 0; i < 7; i++)
    {
        cout << "a[" << i << "]" << " la: " << a[i] << endl;
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 7; j++)
        {
            if (a[i] < a[j])
            {
                swap(a[i], a[j]);
            }
        }
    }
    for (int i = 0; i < 7; i++)
    {
        cout << "a[" << i << "]" << " la: " << a[i] << endl;
    }
}