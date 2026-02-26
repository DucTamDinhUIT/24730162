#include <iostream>
using namespace std;
#include <iostream>
using namespace std;

void nhapMang(int a[][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Nhap phan tu a[" << i << "][" << j << "]: ";
            cin >> a[i][j];
        }
    }
}
void xuatMang(int a[][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int a[100][100], m, n;
    cout << "Nhap so hang va so cot cua mang: ";
    cin >> m >> n;

    // Nhap mang
    nhapMang(a, m, n);

    // Xuat mang
    cout << "Mang vua nhap la:\n";
    xuatMang(a, m, n);

    return 0;
}