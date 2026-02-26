#include <iostream>
#include <string>
using namespace std;

struct NhanVien
{
    string maNV;
    string tenNV;
    float Luong;
    NhanVien *next;
};

struct List
{
    NhanVien *head;
    NhanVien *tail;
};
void initList(List &l)
{
    l.head = NULL;
    l.tail = NULL;
}

NhanVien *CreateNhanVien(string maNV, string tenNV, float Luong)
{
    NhanVien *nv;
    nv = new NhanVien;
    nv->maNV = maNV;
    nv->tenNV = tenNV;
    nv->Luong = Luong;
    nv->next = NULL;
    return nv;
};

void addHead(List &l, NhanVien *nv) {
    if (l.head == NULL)
    {
        l.head = nv;
        l.tail = nv;
    }
    else
    {
        l.head = nv->next;
        l.head = nv;
    }
};

void addTail(List &l, NhanVien *nv) {
    if (l.tail == NULL)
    {
        l.head = nv;
        l.tail = nv;
    }
    else
    {
        l.tail = nv->next;
        l.tail = nv;
    }
};

void PrintList(List l){
    NhanVien *nv;
    nv = l.head;
    if (nv != NULL)
    {
        cout << "ma nhan vien: " << nv->maNV << endl;
        cout << "ten nhan vien: " << nv->tenNV << endl;       
        cout << "luong nhan vien: " << nv->Luong << endl;
        nv = nv->next;
    }
    
}
float MaxLuong(List l, NhanVien nv){
    float maxLuong;
    return maxLuong;
}
int main()
{
    List l;
    initList(l);
    int n;
    string maNV;
    string tenNV;
    float Luong;

    cout << "nhap so nhan vien: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "nhap ma NV: ";
        cin.ignore(); // Clear the input buffer
        getline(cin, maNV);

        cout << "nhap ten NV: ";
        cin.ignore(); // Clear the input buffer
        getline(cin, tenNV);

        cout << "nhap luong NV: ";
        cin >> Luong;
        
        NhanVien * nv = CreateNhanVien(maNV, tenNV, Luong);
        addTail(l, nv);
    }
    PrintList(l);

   //cout << "luong cao nhat la: " << MaxLuong(l);
    
}