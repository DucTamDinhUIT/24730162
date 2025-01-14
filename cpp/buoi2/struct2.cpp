#include <iostream>
#include <math.h>
using namespace std;

struct HocSinh
{
    int id;
    int lop;
    string hoten;
    int diemToan;
    int diemVan;
    int diemAnh;
};

void nhap(HocSinh &a)
{

    cin >> a.id;
    cin >> a.lop;
    cin >> a.hoten;
    cin >> a.diemToan;
    cin >> a.diemVan;
    cin >> a.diemVan;
}

void xuat(HocSinh &a)
{

    cout << a.id << endl;
    cout << a.lop << endl;
    cout << a.hoten << endl;
    cout << a.diemToan << endl;
    cout << a.diemVan << endl;
    cout << a.diemVan << endl;
}

int main()
{
    HocSinh a1;
    nhap(a1);
    xuat(a1);

}