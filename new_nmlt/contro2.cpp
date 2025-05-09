// 2. Tạo biến str lưu chuỗi “hêllo class”, sau đó tạo biến con trỏ p lưu trữ địa chỉ đầu tiên
// của chuỗi. Hãy thực hiện chuyển chuỗi str thành chuỗi ký tự in hoa “HELLO CLASS”
// thông qua sử dụng con trỏ p.

#include <iostream>
using namespace std;
 int main(){
    char str[] = "hello class";
    char *p = str;
    int length = strlen(str);
    
    cout << "Chuoi sau khi chuyen doi: " << str << endl;
    p = str; // Reset pointer to the start of the string
    for (int i = 0; i < length; i++)
    {
        if (*p >= 'a' && *p <= 'z') // Check if the character is lowercase
        {
            *p = *p - ('a' - 'A'); // Convert to uppercase
        }
        p++;
    }
 }