// 2. Viết chương trình quản lý mo ̣t lớp học gòm tói đa 150 sinh viên, mõi sinh viên có các
// thông tin gồm: Mãsinh viên (chuõi 8 kýtự), họ vàtên sinh viên (chuõi 30 kýtự), giới tính
// (nam/nữ), địa chỉliên hê ̣ (chuõi 50 kýtự), điểm 6 môn học. Chương trình phải đảm bảo
// mo ̣t sótính năng:
// a) Nha ̣p mới mo ̣t danh sách sinh viên.
// b) Tìm mo ̣t sinh viên trong danh sách theo mãsinh viên hoặc thêo tên sinh viên.
// c) Thêm mo ̣t sinh viên vào danh sách.
// d) Hủy mo ̣t sinh viên ra khỏi danh sách.
// e) Xuát danh sách sinh viên ra màn hình.
// f) Xuát danh sách các sinh viên còn nợ điểm (điểm < 5) của ít nhát mo ̣t môn học.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct SinhVien {
    string ma;
    string hoTen;
    string gioiTinh;
    string diaChi;
    float diem[6];
};

void nhapSV(SinhVien &sv) {
    cout << "Ma SV: "; cin >> sv.ma;
    cout << "Ho ten: "; cin.ignore(); getline(cin, sv.hoTen);
    cout << "Gioi tinh: "; getline(cin, sv.gioiTinh);
    cout << "Dia chi: "; getline(cin, sv.diaChi);
    cout << "Nhap 6 diem: ";
    for (float &d : sv.diem) cin >> d;
}

void xuatSV(const SinhVien &sv) {
    cout << "Ma: " << sv.ma << ", Ten: " << sv.hoTen
         << ", GT: " << sv.gioiTinh << ", DC: " << sv.diaChi
         << ", Diem: ";
    for (float d : sv.diem) cout << d << " ";
    cout << endl;
}

bool coNoDiem(const SinhVien& sv) {
    for (float d : sv.diem)
        if (d < 5) return true;
    return false;
}

void timSV(const vector<SinhVien>& ds, const string& key) {
    for (const auto& sv : ds)
        if (sv.ma == key || sv.hoTen.find(key) != string::npos)
            xuatSV(sv);
}

int main() {
    vector<SinhVien> lop;
    int n;
    cout << "So sinh vien: "; cin >> n;
    for (int i = 0; i < n; ++i) {
        SinhVien sv;
        nhapSV(sv);
        lop.push_back(sv);
    }

    cout << "\nDS sinh vien:\n";
    for (const auto& sv : lop) xuatSV(sv);

    string key;
    cout << "\nTim theo ma/ten: "; cin.ignore(); getline(cin, key);
    timSV(lop, key);

    cout << "\nSV con no diem:\n";
    for (const auto& sv : lop)
        if (coNoDiem(sv)) xuatSV(sv);

    // Them SV
    SinhVien newSV;
    cout << "\nThem SV:\n"; nhapSV(newSV);
    lop.push_back(newSV);

    // Xoa SV theo ma
    cout << "\nNhap ma SV muon xoa: "; string maXoa; cin >> maXoa;
    lop.erase(remove_if(lop.begin(), lop.end(), [&](SinhVien sv){ return sv.ma == maXoa; }), lop.end());

    cout << "\nDS sau khi xoa:\n";
    for (const auto& sv : lop) xuatSV(sv);

    return 0;
}
