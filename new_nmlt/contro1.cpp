// 1. Cho mảng 1 chiều a có 10 phần tử, biến con trỏ p trỏ tới mảng 1 chiều a. Hãy dùng
// con trỏ p để gán giá trị 100 cho phần tử thứ 5 của mảng. Hãy viết chương trình nhập
// và xuất mảng 1 chiều thông qua con trỏ p.

// 3. Viết hàm nhập một dãy số thực A tùy ý trong đó có sự cấp phát động. Viết hàm sao
// chép dãy số thực A (được nhập bởi hàm trên) sang một dãy B trong đó có sự giải
// phóng vùng nhớ cấp phát động và cấp phát lại ở dãy B.

#include <iostream>
using namespace std;

int main(){

    int a[10];
    int *p = a;
    *(p + 4) = 100; // Khởi tạo phần tử thứ 5 của mảng với giá trị 0

    cout << "Nhap gia tri cho mang 1 chieu: " << endl;
    for (int i = 0; i < 10; ++i) {
        cout << "Nhap phan tu thu " << i + 1 << ": ";
        cin >> *(p + i);
    }
    // Gán giá trị 100 cho phần tử thứ 5 của mảng thông qua con trỏ p
    *(p + 4) = 100;
    // Xuất mảng 1 chiều thông qua con trỏ p
    cout << "Gia tri cua mang 1 chieu la: ";
    for (int i = 0; i < 10; ++i) {
        cout << *(p + i) << " ";
    }
    cout << endl;

}