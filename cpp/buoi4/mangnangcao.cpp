#include <iostream>

class MangMotChieu {
private:
    int* a;
    int n;

public:
    // Nhóm phương thức khởi tạo
    MangMotChieu() : a(nullptr), n(0) {}

    MangMotChieu(int* arr, int size) : n(size) {
        a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = arr[i];
        }
    }

    MangMotChieu(const MangMotChieu& other) : n(other.n) {
        a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = other.a[i];
        }
    }

    void nhap() {
        std::cout << "Nhap so luong phan tu: ";
        std::cin >> n;
        a = new int[n];
        for (int i = 0; i < n; ++i) {
            std::cout << "Nhap a[" << i << "]: ";
            std::cin >> a[i];
        }
    }

    void thietLapMacDinh() {
        n = 5;
        a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = i + 1;
        }
    }

    void thietLapThongTin(int* arr, int size) {
        delete[] a;
        n = size;
        a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = arr[i];
        }
    }

    void thietLapSaoChep(const MangMotChieu& other) {
        delete[] a;
        n = other.n;
        a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = other.a[i];
        }
    }

    friend std::istream& operator>>(std::istream& is, MangMotChieu& mang) {
        mang.nhap();
        return is;
    }

    // Nhóm phương thức cung cấp thông tin
    int getSoPhanTu() const {
        return n;
    }

    int getPhanTu(int index) const {
        if (index >= 0 && index < n) {
            return a[index];
        }
        return -1;
    }

    void xuat() const {
        for (int i = 0; i < n; ++i) {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const MangMotChieu& mang) {
        mang.xuat();
        return os;
    }

    int& operator[](int index) {
        return a[index];
    }

    // Nhóm phương thức cập nhật thông tin
    MangMotChieu& operator=(const MangMotChieu& other) {
        if (this != &other) {
            delete[] a;
            n = other.n;
            a = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = other.a[i];
            }
        }
        return *this;
    }

    void sapXepTangDan() {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (a[i] > a[j]) {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
    }

    void sapXepGiamDan() {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (a[i] < a[j]) {
                    int temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
    }

    // Nhóm phương thức xử lý
    ~MangMotChieu() {
        delete[] a;
    }

    void lietKeChan() const {
        std::cout << "Cac so chan trong mang: ";
        for (int i = 0; i < n; ++i) {
            if (a[i] % 2 == 0) {
                std::cout << a[i] << " ";
            }
        }
        std::cout << std::endl;
    }

    int tinhTong() const {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
        }
        return sum;
    }

    int demLe() const {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] % 2 != 0) {
                count++;
            }
        }
        return count;
    }

    int demXuatHien(int x) const {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == x) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    MangMotChieu mang1;
    mang1.nhap();

    std::cout << "Mang 1: " << mang1;
    std::cout << "So phan tu mang 1: " << mang1.getSoPhanTu() << std::endl;
    std::cout << "Phan tu tai vi tri 2 mang 1: " << mang1.getPhanTu(2) << std::endl;

    MangMotChieu mang2(mang1);
    std::cout << "Mang 2 (sao chep mang 1): " << mang2;

    mang2.sapXepTangDan();
    std::cout << "Mang 2 sau khi sap xep tang dan: " << mang2;

    mang2.sapXepGiamDan();
    std::cout << "Mang 2 sau khi sap xep giam dan: " << mang2;

    mang1.lietKeChan();
    std::cout << "Tong mang 1: " << mang1.tinhTong() << std::endl;
    std::cout << "So luong so le mang 1: " << mang1.demLe() << std::endl;
    std::cout << "So lan xuat hien cua 5 trong mang 1: " << mang1.demXuatHien(5) << std::endl;
    return 0;
}