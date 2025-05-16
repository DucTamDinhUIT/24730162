#include <iostream>
#include <string>
using namespace std;

struct NhanVien
{
    int maNV;
    string tenNV;
    float luong;
    NhanVien *next;
};

struct List
{
    NhanVien *head;
    NhanVien *tail;
};

NhanVien *Create(int maNV, string tenNV, float luong)
{
    NhanVien *p = new NhanVien;
    p->maNV = maNV;
    p->tenNV = tenNV;
    p->luong = luong;
    p->next = NULL;
    return p;
}

void AddHead(List &l, NhanVien *p)
{
    if (l.head == NULL)
    {
        l.head = p;
        l.tail = p;
    }
    else
    {
        l.head = p->next;
        p = l.head;
    }
}
