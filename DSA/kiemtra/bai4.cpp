// Bài 4: Quản lý danh sách công việc trong ngày
// • Mô tả: Hãy viết chương trình quản lý danh sách các nhiệm vụ cần làm trong một ngày
// bằng danh sách liên kết đơn.
// • Yêu cầu:
// 1. Mỗi nhiệm vụ bao gồm tên và mức độ ưu tiên (1-5).
// 2. Cho phép thêm nhiệm vụ mới vào danh sách
// 3. Sắp xếp danh sách theo độ ưu tiên của nhiệm vụ.
// 4. Xuất các công việc có mức độ ưu tiên nhập từ bàn phím
// 5. Hiển thị danh sách nhiệm vụ theo thứ tự ưu tiên.
// 6. Cho phép xóa nhiệm vụ sau khi hoàn thành theo tên nhiệm vụ.

#include <iostream>
#include <string>
using namespace std;

struct Task{
    string name;
    int doUuTien;
    Task* next;
};

struct TaskList{
    Task* head;
    Task* tail;
};
void init(TaskList& list){
    list.head = nullptr;
    list.tail = nullptr;
}
void addTask(TaskList& list, string name, int doUuTien){
    Task* newTask = new Task;
    newTask->name = name;
    newTask->doUuTien = doUuTien;
    newTask->next = nullptr;

    if(list.head == nullptr){
        list.head = newTask;
        list.tail = newTask;
    } else {
        list.tail->next = newTask;
        list.tail = newTask;
    }
}
void sortTasks(TaskList& list){
    if(list.head == nullptr) return;

    for(Task* i = list.head; i != nullptr; i = i->next){
        for(Task* j = i->next; j != nullptr; j = j->next){
            if(i->doUuTien > j->doUuTien){
                swap(i->name, j->name);
                swap(i->doUuTien, j->doUuTien);
            }
        }
    }
}
void displayTasks(TaskList& list){
    Task* current = list.head;
    while(current != nullptr){
        cout << "Ten: " << current->name << ", Do uu tien: " << current->doUuTien << endl;
        current = current->next;
    }
}


void deleteTask(TaskList& list, string name){
    if(list.head == nullptr) return;

    Task* current = list.head;
    Task* previous = nullptr;

    while(current != nullptr && current->name != name){
        previous = current;
        current = current->next;
    }

    if(current == nullptr) return; // Task not found

    if(previous == nullptr){
        list.head = current->next;
    } else {
        previous->next = current->next;
    }

    if(current == list.tail){
        list.tail = previous;
    }

    delete current;
}
int main(){
    TaskList list;
    init(list);

    int n;
    cout << "Nhap so luong cong viec: ";
    cin >> n;

    for(int i = 0; i < n; i++){
        string name;
        int doUuTien;
        cout << "Nhap ten cong viec: ";
        cin.ignore();
        getline(cin, name);

        cout << "Nhap do uu tien (1-5): ";
        cin >> doUuTien;
        addTask(list, name, doUuTien);
    }

    sortTasks(list);
    cout << "Danh sach cong viec sau khi sap xep:" << endl;
    displayTasks(list);

    string nameToDelete;
    cout << "Nhap ten cong viec can xoa: ";
    cin.ignore();
    getline(cin, nameToDelete);
    
    deleteTask(list, nameToDelete);

    cout << "Danh sach cong viec sau khi xoa:" << endl;
    displayTasks(list);

    return 0;
}
