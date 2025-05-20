#include <iostream>
using namespace std;
class Hinh
{
private:
    float a, b; // a: chiều dài, b: chiều rộng
public:
    Hinh(float a, float b);
    ~Hinh();
    void nhap();
    void xuat();
    void tinhChuVi();
    void tinhDienTich();
};
Hinh::Hinh(float a, float b)
{
    this->a = a;
    this->b = b;
}
Hinh::~Hinh()
{
}
class HinhChuNhat : public Hinh
{
private:
public:
    HinhChuNhat(float dai, float rong) : Hinh(dai, rong);

    ~HinhChuNhat();
    void nhap();
    void xuat();
    float tinhChuVi();
    float tinhDienTich();
};

HinhChuNhat::HinhChuNhat(float dai, float rong) : Hinh(dai, rong)
{
}

HinhChuNhat::~HinhChuNhat()
{
}
int main()
{
    HinhChuNhat hcn(0, 0);
    hcn.nhap();
    hcn.xuat();
    hcn.tinhChuVi();
    hcn.tinhDienTich();
    return 0;
}