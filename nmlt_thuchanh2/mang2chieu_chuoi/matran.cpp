#include <iostream>
using namespace std;

int main(){
    int a[50][50]; int b[50][50]; int c[50][50];
    int n, m;
    cout << "nhap so hang: ";
    cin >> n;
    cout << "nhap so cot: ";
    cin >> m;
    cout << "nhap ma tran A: " << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    cout << "ma tran A vua nhap la: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    cout << "nhap ma tran B: " << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> b[i][j];
    cout << "ma tran B vua nhap la: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << b[i][j] << " ";
        cout << endl;
    }
    
    cout << "ma tran sau khi cong la: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            c[i][j] = a[i][j] + b[i][j];
        for (int j = 0; j < m; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }
    cout << "ma tran sau khi nhan la: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) 
            c[i][j] = a[i][j] * b[i][j];
        for (int j = 0; j < m; j++) 
            cout << c[i][j] << " ";
        cout << endl;
    }
    
}