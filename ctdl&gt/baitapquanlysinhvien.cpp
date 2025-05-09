

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct SinhVien
{
    string mssv;
    string ten;
    float diemTB;
};

// Hàm đếm số lượng sinh viên trong file CSV
int demSoLuongSinhVien(const string &tenFile)
{
    ifstream file(tenFile);
    if (!file.is_open())
    {
        cerr << "Không thể mở file để đếm!\n";
        return 0;
    }
    string line;
    int count = 0;
    getline(file, line);
    while (getline(file, line))
    {
        if (!line.empty())
            count++;
    }
    file.close();
    return count;
}

// Hàm đọc file CSV
SinhVien *docFileCSV(const string &tenFile, int &soLuong)
{
    soLuong = demSoLuongSinhVien(tenFile);
    if (soLuong == 0)
        return nullptr;

    SinhVien *danhSachSV = new SinhVien[soLuong];
    ifstream file(tenFile);
    string line;

    if (!file.is_open())
    {
        cerr << "Không thể mở file!\n";
        delete[] danhSachSV;
        return nullptr;
    }

    getline(file, line);
    int i = 0;
    while (getline(file, line) && i < soLuong)
    {
        stringstream ss(line);
        string diemTB;
        getline(ss, danhSachSV[i].mssv, ',');
        getline(ss, danhSachSV[i].ten, ',');
        getline(ss, diemTB, ',');
        try
        {
            danhSachSV[i].diemTB = stof(diemTB);
        }
        catch (const exception &e)
        {
            cerr << "Lỗi chuyển đổi điểm TB tại dòng " << i + 1 << ": " << e.what() << endl;
            danhSachSV[i].diemTB = 0.0;
        }
        i++;
    }
    file.close();
    return danhSachSV;
}

// Hàm tìm kiếm theo MSSV
SinhVien *timSinhVienTheoMSSV(SinhVien *danhSachSV, int soLuong, const string &mssvCanTim)
{
    for (int i = 0; i < soLuong; i++)
    {
        if (danhSachSV[i].mssv == mssvCanTim)
            return &danhSachSV[i];
    }
    return nullptr;
}

// Hàm cập nhật theo MSSV
bool capNhatSinhVienTheoMSSV(SinhVien *danhSachSV, int soLuong, const string &mssvCanCapNhat,
                             const string &tenMoi, float diemTBMoi)
{
    for (int i = 0; i < soLuong; i++)
    {
        if (danhSachSV[i].mssv == mssvCanCapNhat)
        {
            danhSachSV[i].ten = tenMoi;
            danhSachSV[i].diemTB = diemTBMoi;
            return true;
        }
    }
    return false;
}

// Hàm tìm điểm TB cao nhất
float timDiemTBCaoNhat(SinhVien *danhSachSV, int soLuong)
{
    if (soLuong <= 0)
        return 0.0;
    float maxDiemTB = danhSachSV[0].diemTB;
    for (int i = 1; i < soLuong; i++)
    {
        if (danhSachSV[i].diemTB > maxDiemTB)
            maxDiemTB = danhSachSV[i].diemTB;
    }
    return maxDiemTB;
}

// Hàm liệt kê sinh viên có điểm TB cao nhất
void lietKeSVCoDiemTBCaoNhat(SinhVien *danhSachSV, int soLuong)
{
    float maxDiemTB = timDiemTBCaoNhat(danhSachSV, soLuong);
    cout << "Sinh vien co diem trung binh cao nhat (" << maxDiemTB << "):\n";
    for (int i = 0; i < soLuong; i++)
    {
        if (danhSachSV[i].diemTB == maxDiemTB)
        {
            cout << "MSSV: " << danhSachSV[i].mssv << ", Ten: " << danhSachSV[i].ten << endl;
        }
    }
}

// Hàm sắp xếp tăng theo điểm TB (sử dụng Bubble Sort)
void sapXepTangTheoDiemTB(SinhVien *danhSachSV, int soLuong)
{
    for (int i = 0; i < soLuong - 1; i++)
    {
        for (int j = 0; j < soLuong - i - 1; j++)
        {
            if (danhSachSV[j].diemTB > danhSachSV[j + 1].diemTB)
            {
                swap(danhSachSV[j], danhSachSV[j + 1]);
            }
        }
    }
}

// Hàm chèn sinh viên vào danh sách đã sắp xếp
SinhVien *chenSinhVien(SinhVien *danhSachSV, int &soLuong, const SinhVien &svMoi)
{
    SinhVien *newList = new SinhVien[soLuong + 1];
    int i = 0;
    while (i < soLuong && danhSachSV[i].diemTB < svMoi.diemTB)
    {
        newList[i] = danhSachSV[i];
        i++;
    }
    newList[i] = svMoi;
    for (int j = i; j < soLuong; j++)
    {
        newList[j + 1] = danhSachSV[j];
    }
    delete[] danhSachSV;
    soLuong++;
    return newList;
}

// Hàm xóa sinh viên theo tên
SinhVien *xoaSinhVienTheoTen(SinhVien *danhSachSV, int &soLuong, const string &tenCanXoa)
{
    int count = 0;
    for (int i = 0; i < soLuong; i++)
    {
        if (danhSachSV[i].ten == tenCanXoa)
            count++;
    }
    if (count == 0)
        return danhSachSV;

    SinhVien *newList = new SinhVien[soLuong - count];
    int j = 0;
    for (int i = 0; i < soLuong; i++)
    {
        if (danhSachSV[i].ten != tenCanXoa)
        {
            newList[j++] = danhSachSV[i];
        }
    }
    delete[] danhSachSV;
    soLuong -= count;
    return newList;
}

// Hàm in danh sách
void inDanhSach(SinhVien *danhSachSV, int soLuong)
{
    cout << "Danh sach sinh vien:\n";
    for (int i = 0; i < soLuong; i++)
    {
        cout << "MSSV: " << danhSachSV[i].mssv
             << ", Ten: " << danhSachSV[i].ten
             << ", Diem TB: " << danhSachSV[i].diemTB << endl;
    }
}

int main()
{
    // string tenFile = "C:\\Users\\ASUS\\Desktop\24730162\\ctdl&gt\\students.csv"; // Thay bằng đường dẫn
    string tenFile = "students.csv"; // Thay bằng đường dẫn
    int soLuong = 0;
    SinhVien *danhSachSV = docFileCSV(tenFile, soLuong);

    if (danhSachSV == nullptr)
    {
        cout << "Không có dữ liệu sinh viên!\n";
        return 1;
    }

    int luaChon;
    do
    {
        cout << "\n=== MENU ===\n";
        cout << "1. Tim sinh vien theo MSSV\n";
        cout << "2. Cap nhat thong tin sinh vien theo MSSV\n";
        cout << "3. Tim diem trung binh cao nhat\n";
        cout << "4. Liet ke sinh vien co diem TB cao nhat\n";
        cout << "5. Sap xep danh sach tang theo diem TB\n";
        cout << "6. Chen sinh vien vao danh sach da sap xep\n";
        cout << "7. Xoa sinh vien theo ten\n";
        cout << "8. In danh sach sinh vien\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        cin.ignore();

        switch (luaChon)
        {
        case 1:
        {
            string mssvCanTim;
            cout << "Nhap MSSV can tim: ";
            getline(cin, mssvCanTim);
            SinhVien *sv = timSinhVienTheoMSSV(danhSachSV, soLuong, mssvCanTim);
            if (sv)
            {
                cout << "Sinh vien tim thay: MSSV: " << sv->mssv
                     << ", Ten: " << sv->ten << ", Diem TB: " << sv->diemTB << endl;
            }
            else
            {
                cout << "Khong tim thay sinh vien voi MSSV: " << mssvCanTim << endl;
            }
            break;
        }
        case 2:
        {
            string mssv, tenMoi;
            float diemTBMoi;
            cout << "Nhap MSSV can cap nhat: ";
            getline(cin, mssv);
            cout << "Nhap ten moi: ";
            getline(cin, tenMoi);
            cout << "Nhap diem TB moi: ";
            cin >> diemTBMoi;
            cin.ignore();
            if (capNhatSinhVienTheoMSSV(danhSachSV, soLuong, mssv, tenMoi, diemTBMoi))
            {
                cout << "Cap nhat thanh cong!\n";
            }
            else
            {
                cout << "Khong tim thay sinh vien voi MSSV: " << mssv << endl;
            }
            break;
        }
        case 3:
        {
            float maxDiemTB = timDiemTBCaoNhat(danhSachSV, soLuong);
            cout << "Diem trung binh cao nhat: " << maxDiemTB << endl;
            break;
        }
        case 4:
        {
            lietKeSVCoDiemTBCaoNhat(danhSachSV, soLuong);
            break;
        }
        case 5:
        {
            sapXepTangTheoDiemTB(danhSachSV, soLuong);
            cout << "Da sap xep tang theo diem TB!\n";
            inDanhSach(danhSachSV, soLuong);
            break;
        }
        case 6:
        {
            SinhVien svMoi;
            cout << "Nhap MSSV moi: ";
            getline(cin, svMoi.mssv);
            cout << "Nhap ten moi: ";
            getline(cin, svMoi.ten);
            cout << "Nhap diem TB moi: ";
            cin >> svMoi.diemTB;
            cin.ignore();
            danhSachSV = chenSinhVien(danhSachSV, soLuong, svMoi);
            cout << "Chen thanh cong!\n";
            inDanhSach(danhSachSV, soLuong);
            break;
        }
        case 7:
        {
            string tenCanXoa;
            cout << "Nhap ten sinh vien can xoa: ";
            getline(cin, tenCanXoa);
            danhSachSV = xoaSinhVienTheoTen(danhSachSV, soLuong, tenCanXoa);
            cout << "Da xoa sinh vien co ten: " << tenCanXoa << endl;
            inDanhSach(danhSachSV, soLuong);
            break;
        }
        case 8:
        {
            inDanhSach(danhSachSV, soLuong);
            break;
        }
        case 0:
        {
            cout << "Thoat chuong trinh!\n";
            break;
        }
        default:
        {
            cout << "Lua chon khong hop le!\n";
            break;
        }
        }
    } while (luaChon != 0);

    delete[] danhSachSV;
    return 0;
}