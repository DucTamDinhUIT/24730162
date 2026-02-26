#include <iostream>
using namespace std;
typedef struct tagNode
{
    int Info;
    struct tagNode *Next;
} Node;
typedef struct
{
    Node *Head;
    Node *Tail;
} List;
void CreateList(List &l)
{
    l.Head = NULL;
    l.Tail = NULL;
}
Node *CreateNode(int x)
{
    Node *p;
    p = new Node; // cap phat dong
    p->Info = x;
    p->Next = NULL;
    return p;
}
void AddHead(List &l, Node *p)
{
    if (l.Head == NULL)
    {
        l.Head = p;
        l.Tail = p;
    }
    else
    {
        p->Next = l.Head; // da them vao dau
        l.Head = p;
    }
}
void AddTail(List &l, Node *p)
{
    if (l.Head == NULL)
    {
        l.Head = p;
        l.Tail = p;
    }
    else
    {
        l.Tail->Next = p; // them vao duoc roi
        l.Tail = p;       // p la nut cuoi
    }
}
void PrintList(List l)
{
    Node *p;
    p = l.Head;
    while (p != NULL)
    {
        cout << p->Info << "   ";
        p = p->Next;
    }
}

int main()
{
    List l1;
    Node *p;
    int x;
    CreateList(l1);
    for (int i = 1; i <= 4; i++)
    {
        cout << "Nhap x";
        cin >> x;
        p = CreateNode(x); // tra ve dia chi cua nut moi tao
        // AddHead(l1,p);
        AddTail(l1, p);
    }
    cout << "Xuat List: ";
    PrintList(l1);

    return 0;
}