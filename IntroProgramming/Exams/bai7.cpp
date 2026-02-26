// 2. Tạo biến str lưu chuỗi “hêllo class”, sau đó tạo biến con trỏ p lưu trữ địa chỉ đầu tiên
// của chuỗi. Hãy thực hiện chuyển chuỗi str thành chuỗi ký tự in hoa “HELLO CLASS”
// thông qua sử dụng con trỏ p.
#include <iostream>

using namespace std;
int main() {
    char str[] = "hello class";
    char* p = str; // Con trỏ p trỏ tới địa chỉ đầu tiên của chuỗi str

    // Chuyển đổi chuỗi thành chữ hoa thông qua con trỏ p
    for (int i = 0; i < strlen(p); i++) {
        *(p + i) = toupper(*(p + i));
    }

    cout << "Chuoi sau khi chuyen doi: " << p << endl;

    return 0;
}