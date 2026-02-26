/*
Quản lý lịch sử duyệt web
• Mô tả: Viết chương trình để quản lý lịch sử duyệt web của người dùng bằng danh sách
liên kết đơn.
• Yêu cầu:
1. Mỗi trang web gồm tên trang và URL.
2. Mỗi khi người dùng truy cập một trang web mới, trang đó được thêm vào đầu
danh sách.
3. Cho phép người dùng duyệt lại các trang web theo thứ tự đã truy cập.
4. Hiển thị danh sách lịch sử duyệt web.

*/

#include <iostream>
using namespace std;
#include <string>

// struct Point {
//     int x;
//     int y;
// };

struct Web {
    string ten;
    string url;

    Web *next;
};
// struct Node {
//     Web data;
//     Node* next;
// };

void addWeb(Web*& head, const string& ten, const string& url) {
    Web* newWeb = new Web;
  newWeb->ten = ten;
  newWeb->url = url;
  newWeb->next = head;
  head = newWeb;
};

// hien danh sach
void openHis(Web* head) {
    cout   << "Lich su duyet web: " << endl;
    while (head){
        cout << head->ten << " " << head->url << endl;
        head = head->next;
    }


}
int main() {
    Web* head = nullptr;
    string ten, url;
    cout << "Nhap ten trang web: ";
    getline(cin, ten);
    cout << "Nhap url: ";
    getline(cin, url);
    addWeb(head, ten, url);

    openHis(head);
    
    while(head != nullptr) {
        Web* temp = head;
        head = head->next;
        delete temp;
    }
    // Xóa danh sách liên kết
    return 0;
}