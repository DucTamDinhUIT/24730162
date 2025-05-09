// 1. Hãy khai báo kiểu dữ liệu để biểu diễn thông tin của 1 tỉnh gồm mã tỉnh, tên tỉnh, dân số,
// diện tích; nhập xuất thông tin 1 tỉnh và danh sách tỉnh; xuất tỉnh có dân số lớn hơn 1
// triệu, tìm tỉnh có diện tích lớn nhất, …

#include <iostream>
#include <vector>
using namespace std;

struct Tinh {
    string maTinh;
    string tenTinh;
    long danSo;
    float dienTich;
};

void nhapTinh(Tinh &t) {
    cout << "Ma tinh: "; cin >> t.maTinh;
    cout << "Ten tinh: "; cin.ignore(); getline(cin, t.tenTinh);
    cout << "Dan so: "; cin >> t.danSo;
    cout << "Dien tich: "; cin >> t.dienTich;
}

void xuatTinh(const Tinh &t) {
    cout << "Ma: " << t.maTinh << ", Ten: " << t.tenTinh
         << ", Dan so: " << t.danSo << ", Dien tich: " << t.dienTich << endl;
}

void danSoHon1Trieu(const vector<Tinh>& ds) {
    for (const auto& t : ds)
        if (t.danSo > 1000000)
            xuatTinh(t);
}

void tinhLonNhat(const vector<Tinh>& ds) {
    if (ds.empty()) return;
    Tinh maxT = ds[0];
    for (const auto& t : ds)
        if (t.dienTich > maxT.dienTich)
            maxT = t;
    cout << "Tinh co dien tich lon nhat:\n";
    xuatTinh(maxT);
}

int main() {
    int n;
    cout << "Nhap so tinh: "; cin >> n;
    vector<Tinh> ds(n);
    for (auto &t : ds) nhapTinh(t);

    cout << "\nTinh co dan so > 1 trieu:\n";
    danSoHon1Trieu(ds);

    tinhLonNhat(ds);
    return 0;
}

