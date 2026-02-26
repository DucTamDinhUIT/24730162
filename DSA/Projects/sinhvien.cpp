#include "sinhvien.hpp"
SinhVien::SinhVien()
{
}
SinhVien::~SinhVien()
{
}
SinhVien::SinhVien(int mssv, string hoten, string diachi, int tinchi, float dtb)
{
    this->mssv = mssv;
    this->hoten = hoten;
    this->diachi = diachi;
    this->tinchi = tinchi;
    this->dtb = dtb;
}
void SinhVien::xuat(){
    cout << "MSSV: " << mssv << endl;
    cout << "Ho ten: " << hoten << endl;
    cout << "Dia chi: " << diachi << endl;
    cout << "So tin chi: " << tinchi << endl;
    cout << "Diem trung binh: " << dtb << endl;
}
void SinhVien::nhap()
{
    cout << "Nhap MSSV: ";
    cin >> mssv;
    cin.ignore();
    cout << "Nhap ho ten: ";
    getline(cin, hoten);
    cout << "Nhap dia chi: ";
    getline(cin, diachi);
    cout << "Nhap so tin chi: ";
    cin >> tinchi;
    cout << "Nhap diem trung binh: ";
    cin >> dtb;
}



