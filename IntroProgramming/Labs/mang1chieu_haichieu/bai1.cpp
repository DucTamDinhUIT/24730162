// BÀI TẬP BẮT BUỘC
// 1. Xuất các số nguyên tố có trong mảng số nguyên ra màn hình.
// 2. Kiểm tra mảng có đối xứng hay không ?
// 3. Viết hàm xóa phần tử có chỉ số k trong mảng số nguyên a có n phần tử. Nếu giá
// trị của k<0 hoặc k>=n thì không xóa và hàm trả về giá trị 0. Ngược lại ta xóa giá
// trị phần tử a[k] và hàm trả về giá trị 1.
// 4. Tìm vị trí phần tử lớn nhất trong mảng.
// 5. Tìm vị trí của phần tử có giá trị âm lớn nhất trong mảng số nguyên .

#include <iostream>
using namespace std;

bool kiemtraSNT(int a)
{
    if (a < 2)
        return false;
    for (int i = 2; i <= a / 2; i++)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}

bool kiemtraDoiXung(int a[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        if (a[i] != a[n - i - 1])
            return false;
    }
    return true;
}
int xoaPhanTu(int a[], int n, int k)
{
    if (k < 0 || k >= n)
        return 0;
    for (int i = k; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    return 1;
}
int timMax(int a[], int n)
{
    int max = a[0];
    int vt = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            vt = i;
        }
    }
    return vt;
}
int timMaxAm(int a[], int n)
{
    int max = -1;
    int vt = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0 && a[i] > max)
        {
            max = a[i];
            vt = i;
        }
    }
    return vt;
}
int main()
{
    int a[50];
    cout << "nhap so luong: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // xuat ra màn hình
    for (int i = 0; i < n; i++)
    {
        if (kiemtraSNT(a[i]))
        {
            cout << a[i] << " ";
        }
    }
    cout << endl;
    // kiem tra doi xung
    if (kiemtraDoiXung(a, n))
    {
        cout << "mang doi xung" << endl;
    }
    else
    {
        cout << "mang khong doi xung" << endl;
    }
    // xoa phan tu
    int k;
    cout << "nhap vi tri can xoa: ";
    cin >> k;
    xoaPhanTu(a, n, k);
    cout << "mang sau khi xoa la: ";
    for (int i = 0; i < n - 1; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    // tim phan tu max
    int vtMax = timMax(a, n);
    cout << "vi tri phan tu max la: " << vtMax << endl;
    cout << "phan tu max la: " << a[vtMax] << endl;
    // tim phan tu am max
    int vtMaxAm = timMaxAm(a, n);
    if (vtMaxAm != -1)
    {
        cout << "vi tri phan tu am max la: " << vtMaxAm << endl;
        cout << "phan tu am max la: " << a[vtMaxAm] << endl;
    }
    else
    {
        cout << "khong co phan tu am" << endl;
    }
    return 0;
}