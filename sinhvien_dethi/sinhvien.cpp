#include "sinhvien.hpp"
SinhVien::SinhVien(/* args */)
{
}

SinhVien::~SinhVien()
{
}
SinhVien::SinhVien(int mssv, string hoten, const string &diachi, int tinchi, float dtb)
{
    mssv = mssv;
    hoten = hoten;
    this->diachi = diachi;
    tinchi = tinchi;
    dtb = dtb;
}
void SinhVien::nhap()
{
    cout << "nhap mssv: ";
    cin >> mssv;
    cout << "nhap ho ten sinh vien: ";
    cin.ignore();
    getline(cin, hoten);
    cout << "nhap dia chi sinh vien: ";
    cin.ignore();
    getline(cin, diachi);
    cout << "nhap tin chi: ";
    cin >> tinchi;
    cout << "nhap dtb: ";
    cin >> dtb;
}

void SinhVien::xuat()
{
    cout << "mssv: " << mssv << endl;
    cout << "ho ten sinh vien: " << hoten << endl;
    cout << "dia chi sinh vien: " << diachi << endl;
    cout << "tin chi: " << tinchi << endl;
    cout << "dtb: " << dtb << endl;
}