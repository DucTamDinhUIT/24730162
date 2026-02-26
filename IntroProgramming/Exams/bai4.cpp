
// 3. Viết chương trình sử dụng struct đểbiểu diễn phân só
// a) Khai báo kiểu dữ liệu phân số
// b) Nhập / Xuất phân số
// c) Rút gọn phân số
// d) Tính tổng, hiệu, tích, thương hai phân số
// e) Kiểm tra phân số tối giản
// f) Quy đồng hai phân số
// g) Kiểm tra phân số âm hay dương
// h) So sánh hai phân số

#include <iostream>
using namespace std;

struct PhanSo {
    int tu, mau;
};

int gcd(int a, int b) {
    return b == 0 ? abs(a) : gcd(b, a % b);
}

void rutGon(PhanSo &ps) {
    int ucln = gcd(ps.tu, ps.mau);
    ps.tu /= ucln;
    ps.mau /= ucln;
    if (ps.mau < 0) {
        ps.tu *= -1;
        ps.mau *= -1;
    }
}

void nhapPS(PhanSo &ps) {
    cout << "Nhap tu & mau: "; cin >> ps.tu >> ps.mau;
    rutGon(ps);
}

void xuatPS(const PhanSo &ps) {
    cout << ps.tu << "/" << ps.mau << endl;
}

PhanSo cong(PhanSo a, PhanSo b) {
    PhanSo kq = {a.tu * b.mau + b.tu * a.mau, a.mau * b.mau};
    rutGon(kq);
    return kq;
}

PhanSo hieu(PhanSo a, PhanSo b) {
    b.tu *= -1;
    return cong(a, b);
}

PhanSo tich(PhanSo a, PhanSo b) {
    PhanSo kq = {a.tu * b.tu, a.mau * b.mau};
    rutGon(kq);
    return kq;
}

PhanSo thuong(PhanSo a, PhanSo b) {
    PhanSo kq = {a.tu * b.mau, a.mau * b.tu};
    rutGon(kq);
    return kq;
}

bool laToiGian(const PhanSo& ps) {
    return gcd(ps.tu, ps.mau) == 1;
}

void quyDong(PhanSo &a, PhanSo &b) {
    int lcm = a.mau * b.mau / gcd(a.mau, b.mau);
    a.tu *= lcm / a.mau; a.mau = lcm;
    b.tu *= lcm / b.mau; b.mau = lcm;
}

int soSanh(PhanSo a, PhanSo b) {
    quyDong(a, b);
    if (a.tu > b.tu) return 1;
    if (a.tu < b.tu) return -1;
    return 0;
}

bool laDuong(const PhanSo& ps) {
    return ps.tu * ps.mau > 0;
}

int main() {
    PhanSo a, b;
    nhapPS(a); nhapPS(b);

    cout << "Tong: "; xuatPS(cong(a, b));
    cout << "Hieu: "; xuatPS(hieu(a, b));
    cout << "Tich: "; xuatPS(tich(a, b));
    cout << "Thuong: "; xuatPS(thuong(a, b));

    cout << "Toi gian? " << (laToiGian(a) ? "Yes" : "No") << endl;
    cout << "So sanh: " << soSanh(a, b) << endl;
    cout << "Phan so a " << (laDuong(a) ? "Duong" : "Am") << endl;
    return 0;
}
