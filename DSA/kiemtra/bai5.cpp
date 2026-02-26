// Bài 5: Quản lý danh sách bài hát (Playlist)
// • Mô tả: Viết chương trình quản lý danh sách bài hát sử dụng danh sách liên kết đơn.
// • Yêu cầu:
// 1. Mỗi bài hát bao gồm tên bài hát và tên ca sĩ.
// 2. Cho phép thêm bài hát mới vào danh sách phát (thêm vào cuối danh sách).
// 3. Xóa 1 bài hát theo tên
// 4. Cho phép phát bài hát theo thứ tự từ đầu đến cuối danh sách.
// 5. Hiển thị danh sách bài hát hiện có trong playlist.
#include <iostream>
#include <string>
using namespace std;

struct BaiHat {
    string tenBaiHat;
    string tenCaSi;
    BaiHat* tiepTheo;
};
class DanhSachPhat {
private:
    BaiHat* dau;
public:         
    DanhSachPhat() {
        dau = nullptr;
    }
    void themBaiHat(string tenBaiHat, string tenCaSi) {
        BaiHat* baiHatMoi = new BaiHat;
        baiHatMoi->tenBaiHat = tenBaiHat;
        baiHatMoi->tenCaSi = tenCaSi;
        baiHatMoi->tiepTheo = nullptr;

        if (dau == nullptr) {
            dau = baiHatMoi;
        } else {
            BaiHat* tam = dau;
            while (tam->tiepTheo != nullptr) {
                tam = tam->tiepTheo;
            }
            tam->tiepTheo = baiHatMoi;
        }
    }
    void xoaBaiHat(string tenBaiHat) {
        if (dau == nullptr) {
            cout << "Danh sach phat trong." << endl;
            return;
        }

        if (dau->tenBaiHat == tenBaiHat) {
            BaiHat* tam = dau;
            dau = dau->tiepTheo;
            delete tam;
            cout << "Da xoa bai hat: " << tenBaiHat << endl;
            return;
        }

        BaiHat* hienTai = dau;
        while (hienTai->tiepTheo != nullptr && hienTai->tiepTheo->tenBaiHat != tenBaiHat) {
            hienTai = hienTai->tiepTheo;
        }

        if (hienTai->tiepTheo == nullptr) {
            cout << "Khong tim thay bai hat: " << tenBaiHat << endl;
        } else {
            BaiHat* tam = hienTai->tiepTheo;
            hienTai->tiepTheo = tam->tiepTheo;
            delete tam;
            cout << "Da xoa bai hat: " << tenBaiHat << endl;
        }
    }
    void phatBaiHat() {
        if (dau == nullptr) {
            cout << "Danh sach phat trong." << endl;
            return;
        }

        BaiHat* tam = dau;
        while (tam != nullptr) {
            cout << "Dang phat: " << tam->tenBaiHat << " cua " << tam->tenCaSi << endl;
            tam = tam->tiepTheo;
        }
    }
    void hienThiDanhSach() {
        if (dau == nullptr) {
            cout << "Danh sach phat trong." << endl;
            return;
        }

        BaiHat* tam = dau;
        cout << "Danh sach phat hien tai:" << endl;
        while (tam != nullptr) {
            cout << "- " << tam->tenBaiHat << " cua " << tam->tenCaSi << endl;
            tam = tam->tiepTheo;
        }
    }
    ~DanhSachPhat() {
        BaiHat* hienTai = dau;
        while (hienTai != nullptr) {
            BaiHat* baiHatTiepTheo = hienTai->tiepTheo;
            delete hienTai;
            hienTai = baiHatTiepTheo;
        }
    }
};