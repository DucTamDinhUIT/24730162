#include <iostream>
#include <string>
#include "sinhvien.hpp"
using namespace std;

class Truong : public SinhVien
{
private:
    SinhVien *sv;
    int soluong;

public:
    Truong(/* args */);
    ~Truong();
    virtual void nhapDanhSach();
    virtual void xuatDanhSach();
};
