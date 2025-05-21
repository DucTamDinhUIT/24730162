#include "truong.hpp"
Truong::Truong(/* args */)
{
}

Truong::~Truong()
{
}

void Truong::nhapDanhSach()
{
    cout << "nhap so luong sinh vien: ";
    cin >> soluong;
    sv = new SinhVien *[soluong];
    for (int i = 0; i < soluong; i++)
    {
        int loai;
        cout << "nhap loai sinh vien: Cao dang (1) or Dai hoc (2) ";
        cin >> loai;
        if (loai == 1)
        {
            sv[i] = new CaoDang();
        }
        else if (loai == 2)
        {
            sv[i] = new DaiHoc();
        }
    }
}

void Truong::xuatDanhSach()
{
}
