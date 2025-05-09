#include <iostream>
using namespace std;

int main() {
    const int size = 10;
    int a[size];

    // Nhập mảng 1 chiều thông qua con trỏ p
    int* p = a;
    cout << "Nhap gia tri cho mang 1 chieu: " << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> *(p + i);
    }

    // Gán giá trị 100 cho phần tử thứ 5 của mảng thông qua con trỏ p
    *(p + 4) = 100;

    // Xuất mảng 1 chiều thông qua con trỏ p
    cout << "Gia tri cua mang 1 chieu la: ";
    for (int i = 0; i < size; ++i) {
        cout << *(p + i) << " ";
    }
    cout << endl;

    return 0;
}

// Code lại bài này với cách tiếp cận tương tự nhưng sử dụng hàm và vẫn dùng con trỏ:

#include <iostream>
using namespace std;

void nhapMang(int* p, int size) {
    cout << "Nhap gia tri cho mang 1 chieu: " << endl;
    for (int i = 0; i < size; ++i) {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> *(p + i);
    }
}

void ganGiaTri(int* p, int index, int value) {
    *(p + index) = value;
}

void xuatMang(int* p, int size) {
    cout << "Gia tri cua mang 1 chieu la: ";
    for (int i = 0; i < size; ++i) {
        cout << *(p + i) << " ";
    }
    cout << endl;
}

int main() {
    const int size = 10;
    int a[size];
    int* p = a;

    nhapMang(p, size);
    ganGiaTri(p, 4, 100); // Gán giá trị 100 cho phần tử thứ 5
    xuatMang(p, size);

    return 0;
}
#include <iostream>
using namespace std;

void nhapDaySoThuc(double*& A, int& n) {
    cout << "Nhap so luong phan tu cua day so thuc: ";
    cin >> n;
    A = new double[n];
    cout << "Nhap gia tri cho day so thuc: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> A[i];
    }
}

void saoChepDaySoThuc(double* A, int n, double*& B) {
    delete[] B; // Giải phóng vùng nhớ cũ của B nếu có
    B = new double[n];
    for (int i = 0; i < n; ++i) {
        B[i] = A[i];
    }
}

int main() {
    double* A = nullptr;
    double* B = nullptr;
    int n;

    nhapDaySoThuc(A, n);
    saoChepDaySoThuc(A, n, B);

    cout << "Day so thuc A: ";
    for (int i = 0; i < n; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;

    cout << "Day so thuc B: ";
    for (int i = 0; i < n; ++i) {
        cout << B[i] << " ";
    }
    cout << endl;

    delete[] A; // Giải phóng vùng nhớ của A
    delete[] B; // Giải phóng vùng nhớ của B

    return 0;
}