#ifndef SINHVIEN_HPP
#define SINHVIEN_HPP

#include <iostream>
#include <string>

using namespace std;
class SinhVien
{
protected:
    int mssv;
    string hoten;
    string diachi;
    int tinchi;
    float dtb;

public:
    SinhVien(/* args */);
    ~SinhVien();
    SinhVien(int mssv, string hoten, const string &diachi, int tinchi, float dtb);
    virtual void nhap();
    virtual void xuat();
};

#endif // SINHVIEN_HPP
