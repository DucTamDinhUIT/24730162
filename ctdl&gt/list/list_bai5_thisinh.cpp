#include <iostream>
#include <string>
using namespace std;
struct ThiSinh
{
    string maTS;
    string tenTS;
    float Toan;
    float Ly;
    float AnhVan;
    string NganhXT;
    ThiSinh *next;
};

struct List
{
    ThiSinh *head;
    ThiSinh *tail;
};

ThiSinh *CreateNode(string maTS, string tenTS, float Toan, float Ly, float AnhVan, string NganhXT)
{
    ThiSinh *p;
    p = new ThiSinh;
    p->maTS = maTS;
    p->tenTS = tenTS;
    p->Toan = Toan;
    p->Ly = Ly;
    p->AnhVan = AnhVan;
    p->NganhXT = NganhXT;
    p->next = NULL;
    return p;
};
void AddHead(List &l, ThiSinh *p)
{
    if (l.head == NULL)
    {
        l.head = p;
        l.tail = p;
        /* code */
    }
    else
    {
        p->next = l.head;
        l.head = p;
    }
}

void PrintList(List l){
    ThiSinh * p;
    p = l.head;
    while (p != NULL)
    {
        cout << "Ma ts: " << p->maTS << endl;
        cout << "Ten thi sinh: " << p->tenTS << endl;
        cout << "Diem toan: " << p->Toan << endl;
        cout << "Diem ly: " << p->Ly << endl;
        cout << "Diem anh van: " << p->AnhVan << endl;
        cout << "Nganh xet tuyen: " << p->NganhXT << endl;
        p = p->next;
    }
    
}
int main(){
    List l;
    l.head = NULL;
    l.tail = NULL;
    int a;
    string maTS;
    string tenTS;
    float Toan;
    float Ly;
    float AnhVan;
    string NganhXT;

    cout << "nhap so thi sinh: ";
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        cout << "nhap ma thi sinh: ";
        cin >> maTS;
        cout << "nhap ten thi sinh: ";
        cin >> tenTS;
        cout << "nhap diem Toan thi sinh: ";
        cin >> Toan;
        cout << "nhap diem Ly thi sinh: ";
        cin >> Ly;
        cout << "nhap diem Anh Van thi sinh: ";
        cin >> AnhVan;
        cout << "nhap nganh cua thi sinh: ";
        cin >> NganhXT;
        ThiSinh * p = CreateNode(maTS, tenTS, Toan, Ly, AnhVan,NganhXT);
        AddHead(l, p);
    }
    PrintList(l);
    
}
