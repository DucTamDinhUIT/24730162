#include <iostream>
using namespace std;
void nhap(int m[50], int &o)
{
    for (int i = 0; i < o; i++)
    {
        cout << "nhap a" << i << ": ";
        cin >> m[i];
    }
}

void xuat(int n[50], int &o)
{
    for (int i = 0; i < o; i++)
    {
        cout << "a" << i << " la: ";
        cout << n[i] << endl;
    }
}

void sapxep(int p[50], int &o)
{
    cout << "mang sai sap xep la: " << endl;
    for (int i = 0; i < o - 1; i++)
    {
        for (int j = i + 1; j < o; j++)
        {
            if (p[j] < p[i])
            {
                int temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

int main()
{
    int a[50], b;
    cin >> b;
    nhap(a, b);
    sapxep(a, b);
    xuat(a, b);
}