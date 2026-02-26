// Hãy khai báo kiểu dữ liệu để biểu diễn thông tin của 1 tỉnh gồm mã tỉnh, tên tỉnh, dân số,
// diện tích; nhập xuất thông tin 1 tỉnh và danh sách tỉnh; xuất tỉnh có dân số lớn hơn 1
// triệu, tìm tỉnh có diện tích lớn nhất, …

#include <iostream>
using namespace std;

struct Tinh {
    int maTinh;
    string tenTinh;
    int danSo;
    float dienTich;
};

int main(){
    Tinh a[100];
    int n;
    
    cout << "Nhap so luong tinh: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "nhap tinh thu " << i +1 << endl;
        cout << "Nhap ma tinh: ";
        cin >> a[i].maTinh;
        cin.ignore(); // Bỏ qua ký tự newline còn lại trong bộ đệm
        cout << "Nhap ten tinh: ";
        getline(cin, a[i].tenTinh); // Sử dụng getline để nhập chuỗi có khoảng trắng
        cout << "Nhap dan so: ";
        cin >> a[i].danSo;
        cout << "Nhap dien tich: ";
        cin >> a[i].dienTich;
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << "Tinh thu " << i + 1 << endl;
        cout << "Ma tinh: " << a[i].maTinh << endl;
        cout << "Ten tinh: " << a[i].tenTinh << endl;
        cout << "Dan so: " << a[i].danSo << endl;
        cout << "Dien tich: " << a[i].dienTich << endl;
    }
    
}

