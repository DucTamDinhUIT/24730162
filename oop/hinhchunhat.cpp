#include <iostream>

class HinhChuNhat
{
private:
    float dai, rong;

public:
    HinhChuNhat(float dai, float rong);
    ~HinhChuNhat();
    void nhap();
    void xuat();
    void tinhChuVi();
    void tinhDienTich();
};
HinhChuNhat::HinhChuNhat(float dai, float rong)
{
    this->dai = dai;
    this->rong = rong;
}

HinhChuNhat::~HinhChuNhat()
{
}

void HinhChuNhat::nhap()
{
    std::cout << "Nhap chieu dai: ";
    std::cin >> dai;
    std::cout << "Nhap chieu rong: ";
    std::cin >> rong;
}

void HinhChuNhat::xuat()
{
    std::cout << "Hinh chu nhat co chieu dai: " << dai << " va chieu rong: " << rong << std::endl;
}

void HinhChuNhat::tinhChuVi()
{
    float chuVi = 2 * (dai + rong);
    std::cout << "Chu vi hinh chu nhat: " << chuVi << std::endl;
}

void HinhChuNhat::tinhDienTich()
{
    float dienTich = dai * rong;
    std::cout << "Dien tich hinh chu nhat: " << dienTich << std::endl;
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