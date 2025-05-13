#include <iostream>

int main() {
    int* ptr = nullptr; // Khởi tạo con trỏ null

    int value = 10;
    ptr = &value; // Gán địa chỉ của biến value cho con trỏ

    std::cout << "Giá trị của value: " << *ptr << std::endl;

    return 0;
}