// 4. Viết chương trình quản lýthêo kiểu dữ liệu cấu trúc NGÀY như khai báo:
// typedef struct
// {
// int ngay;
// int thang;
// int nam;
// } NGAY;
// Chương trình phải đảm bảo mo ̣t sótính năng:
// g) Nha ̣p/Xuất Ngày.
// h) Tính số ngày trong năm. Cho biết có phải năm nhuận.
// i) Tính ngày trước và ngày sau của ngày vừa nhập.

#include <iostream>
using namespace std;

struct NGAY {
    int ngay, thang, nam;
};

bool namNhuan(int nam) {
    return (nam % 400 == 0) || (nam % 4 == 0 && nam % 100 != 0);
}

int soNgayTrongThang(int thang, int nam) {
    int d[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (thang == 2 && namNhuan(nam)) return 29;
    return d[thang];
}

void nhapNgay(NGAY &d) {
    cout << "Nhap ngay thang nam: "; cin >> d.ngay >> d.thang >> d.nam;
}

void xuatNgay(const NGAY& d) {
    cout << d.ngay << "/" << d.thang << "/" << d.nam << endl;
}

NGAY ngaySau(NGAY d) {
    ++d.ngay;
    if (d.ngay > soNgayTrongThang(d.thang, d.nam)) {
        d.ngay = 1;
        ++d.thang;
        if (d.thang > 12) {
            d.thang = 1;
            ++d.nam;
        }
    }
    return d;
}

NGAY ngayTruoc(NGAY d) {
    --d.ngay;
    if (d.ngay == 0) {
        --d.thang;
        if (d.thang == 0) {
            d.thang = 12;
            --d.nam;
        }
        d.ngay = soNgayTrongThang(d.thang, d.nam);
    }
    return d;
}

int main() {
    NGAY d;
    nhapNgay(d);
    cout << "Ngay vua nhap: "; xuatNgay(d);
    cout << "La nam nhuon? " << (namNhuan(d.nam) ? "Yes" : "No") << endl;

    cout << "Ngay truoc: "; xuatNgay(ngayTruoc(d));
    cout << "Ngay sau: "; xuatNgay(ngaySau(d));
    return 0;
}
