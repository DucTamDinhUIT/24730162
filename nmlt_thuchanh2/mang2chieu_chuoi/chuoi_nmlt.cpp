// Chuỗi ký tự
// 9. Đếm số từ trong 1 chuỗi
// 10.Đổi kí tự đầu tiên của mỗi từ thành chữ in hoa
// 11. Bỏ các ký tự khoảng trắng thừa

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string n;

    cout << "nhap chuoi: ";
    getline(cin, n);

    // so ky tu
    int count = 0;
    int id = 0;
    while (n[id] != '\0')
    {
        count++;
        id++;
    }
    cout << "so ky tu la: " << count << endl;
    
}