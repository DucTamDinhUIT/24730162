#include <iostream>
#include <string>
using namespace std;
class SinhVien
{
private:
    string hoten;
    float diem;

public:
    SinhVien() {};
    SinhVien(string hoten, float diem)
    {
        this->hoten = hoten;
        this->diem = diem;
    };
    ~SinhVien() {};
    virtual void nhap()
    {
        cout << "nhap ho ten: ";
        getline(cin, hoten);
        cout << "diem: ";
        cin >> diem;
    }
    virtual void xuat()
    {
        cout << "Sinh vien: " << hoten << " co so diem la: " << diem << endl;
    }
};

class CaoDang : public SinhVien
{
private:
    float xet_tot_nghiep;
public:
    CaoDang(/* args */);
    ~CaoDang();

};

CaoDang::CaoDang(/* args */)
{
}

CaoDang::~CaoDang()
{
}

class DaiHoc : public SinhVien
{
private:
    float diem_luan_van;
public:
    DaiHoc(/* args */);
    ~DaiHoc();
};

DaiHoc::DaiHoc(/* args */)
{
}

DaiHoc::~DaiHoc()
{
}


int main()
{
    SinhVien * a;
    a->nhap();
    a->xuat();
    
}
