// Cho mảng 1 chiều a có 10 phần tử, biến con trỏ p trỏ tới mảng 1 chiều a. Hãy dùng
// con trỏ p để gán giá trị 100 cho phần tử thứ 5 của mảng. Hãy viết chương trình nhập
// và xuất mảng 1 chiều thông qua con trỏ p.


#include <iostream>
using namespace std;

int main() {
    int a[10];
    int* p = a;

    // Nhập mảng thông qua con trỏ
    cout << "Nhap 10 phan tu cho mang:\n";
    for (int i = 0; i < 10; i++) {
        cout << "a[" << i << "] = ";
        cin >> *(p + i);
    }

    // Gán giá trị 100 cho phần tử thứ 5 (chỉ số 4)
    *(p + 4) = 100;

    // Xuất mảng thông qua con trỏ
    cout << "\nMang sau khi gan phan tu thu 5 = 100:\n";
    for (int i = 0; i < 10; i++) {
        cout << *(p + i) << " ";
    }

    return 0;
}
