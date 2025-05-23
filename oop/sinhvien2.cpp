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

public:
    SinhVien(/* args */);
    ~SinhVien();
    SinhVien(int mssv, string hoten, string diachi, int tinchi, float dtb)
    {
        this->mssv = mssv;
        this->hoten = hoten;
        this->diachi = diachi;
        this->tinchi = tinchi;
        this->dtb = dtb;
    };
    void nhap()
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
    };
    void xuat()
    {
        cout << "MSSV: " << mssv << endl;
        cout << "Ho ten: " << hoten << endl;
        cout << "Dia chi: " << diachi << endl;
        cout << "So tin chi: " << tinchi << endl;
        cout << "Diem trung binh: " << dtb << endl;
    };
};

class CaoDang : public SinhVien
{
private:
    float diem_tn;

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

class DaiHoc
{
private:
    string ten_lv;
    float diem_lv;
public:
    DaiHoc(/* args */);
    DaiHoc();
};
DaiHoc::DaiHoc(/* args */)
{
}
DaiHoc::DaiHoc()
{
}
