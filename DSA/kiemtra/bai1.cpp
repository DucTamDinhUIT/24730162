// Nhập số ở hệ 10, đổi sang hệ 16 dùng danh sách liên kết 

#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

// them node 

void push(Node*& head, char data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode; 
}
// in node
void printList (Node* head)
{
    while (head != nullptr){
        cout << head -> data;
        head = head -> next;
    }
    cout << endl;
}

// chuyen he 10 to 16

void convertToHex(int decimal, Node*& head) {
    if (decimal == 0) {
        return;
    }
    int remainder = decimal % 16;
    char hexChar;
    if (remainder < 10) {
        hexChar = '0' + remainder; 
    } else {
        hexChar = 'A' + (remainder - 10); 
    }
    push(head, hexChar);
    convertToHex(decimal / 16, head);
}

int main() {
    int decimal;
    cout << "Nhap so thap phan ";
    cin >> decimal;

    Node* head = nullptr;
    convertToHex(decimal, head);

    cout << "So he 16 la : ";
    printList(head);

    // Giai phong bo nho
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
