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

void xoaphantu(int r[50], int &o, int x)
{
    int i = 0, j;
    while ((i < o) && r[i] != x)
        i++;
    if (i < o)
    {
        for (j = i + 1; j < o; j++)
            r[j - 1] = r[j];
        o--;
    }
}

// void xoaX(int a[], int &n, int x)
// {
//     int i,j;
//     i=0;
//     while((i<n)&&(a[i]!=x))
//         i++;

//     if(i<n) //tim thay tai vi tri i
//     {
//         for(j=i+1;j<n;j++)
//             a[j-1] = a[j];
//         n--;
//     }
// }
int main()
{
    int a[50], b;
    cin >> b;
    nhap(a, b);
    sapxep(a, b);
    xuat(a, b);
    xoaphantu(a, b, 6);
    xuat(a, b);
}