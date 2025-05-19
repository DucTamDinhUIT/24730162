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
    // doi ky tu
    for (int i = 0; i < count; i++)
    {
        if (i == 0 || n[i - 1] == ' ')
        {
            if (n[i] >= 'a' && n[i] <= 'z')
            {
                n[i] -= 32;
            }
        }
        else
        {
            if (n[i] >= 'A' && n[i] <= 'Z')
            {
                n[i] += 32;
            }
        }
    }
    cout << "chuoi sau khi doi ky tu: " << n << endl;
    // bo khoang trang
    string result = "";
    for (int i = 0; i < count; i++)
    {
        if (n[i] != ' ')
        {
            result += n[i];
        }
        else
        {
            if (result[result.length() - 1] != ' ')
            {
                result += n[i];
            }
        }
    }
    // bo khoang trang o cuoi
    if (result[result.length() - 1] == ' ')
    {
        result = result.substr(0, result.length() - 1);
    }
    cout << "chuoi sau khi bo khoang trang: " << result << endl;
}