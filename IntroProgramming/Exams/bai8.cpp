// 3. Viết hàm nhập một dãy số thực A tùy ý trong đó có sự cấp phát động. Viết hàm sao
// chép dãy số thực A (được nhập bởi hàm trên) sang một dãy B trong đó có sự giải
// phóng vùng nhớ cấp phát động và cấp phát lại ở dãy B.
#include <iostream>
#include <cstring>
using namespace std;
void nhapMang(float*& arr, int& n) {
    cout << "Nhap so phan tu: ";
    cin >> n;
    arr = new float[n];
    cout << "Nhap cac phan tu:\n";
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }
}
void saoChepMang(float*& arr, float*& arrCopy, int n) {
    delete[] arrCopy; // Giải phóng vùng nhớ cũ
    arrCopy = new float[n]; // Cấp phát lại cho mảng sao chép
    memcpy(arrCopy, arr, n * sizeof(float)); // Sao chép dữ liệu
}
void xuatMang(float* arr, int n) {
    cout << "Mang: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    float* arr = nullptr;
    float* arrCopy = nullptr;
    int n;

    nhapMang(arr, n);
    xuatMang(arr, n);

    saoChepMang(arr, arrCopy, n);
    cout << "Mang sau khi sao chep:\n";
    xuatMang(arrCopy, n);

    delete[] arr;
    delete[] arrCopy;

    return 0;
}