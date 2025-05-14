#include <iostream>
#include <string>
using namespace std;

struct SinhVien
{
    string maSV;
    string tenSV;
    SinhVien *next;
};

struct List
{
    SinhVien *head;
    SinhVien *tail;
};

SinhVien *CreateNode(string maSV, string tenSV)
{
    SinhVien *p;
    p = new SinhVien;
    p->maSV = maSV;
    p->tenSV = tenSV;
    p->next = NULL;
    return p;
};

void AddHead(List &l, SinhVien *p)
{
    if (l.head == NULL)
    {
        l.head = p;
        l.tail = p;
    }
    else
    {
        p->next = l.head;
        l.head = p;
    }
}
// void AddAfter(List &l, SinhVien *p){
//     if (condition)
//     {
//         /* code */
//     }
//     else
//     {
//         p->next = l.head
//     }
// }
void PrintList(List l)
{
    SinhVien *p;
    p = l.head;
    while (p != NULL)
    {
        cout << "ma sinh vien: " << p->maSV << endl; 
        cout << "ten sinh vien: " << p->tenSV << endl;
        p = p->next;
    }
}

int main()
{
    List l;
    l.head = NULL;
    l.tail = NULL;
    int a;
    string maSV, tenSV;
    cout << "nhap so luong sinh vien: ";
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        cout << "nhap ma sv: ";
        cin >> maSV;
        cout << "nhap ten sv: ";
        cin >> tenSV;
        SinhVien *p = CreateNode(maSV, tenSV);
        AddHead(l, p);

    }
    PrintList(l);
}
