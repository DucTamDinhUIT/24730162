#include <iostream>
#include <string>
using namespace std;
 class SinhVien
 {
 private:
    int mssv;
    string hoten;
    string diachi;
    int tinchi;
    float dtb;
    /* data */
 public:
    SinhVien();
    SinhVien(int mssv, string hoten, string diachi, int tinchi, float dtb);
    ~SinhVien();
    virtual void nhap();
    virtual void xuat();
 };
 