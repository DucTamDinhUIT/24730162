#include <iostream>
using namespace std;

// khai bao nut
struct Node
{
    int bienso;
    Node *next;
};

struct List
{
    Node *head;
    Node *tail;
};

Node * CreateNode(int x)
{
    Node *p;
    p = new Node; // cap phat dong
    p->bienso = x;
    p->next = NULL;
    return p;
}

void AddHead(List &l, Node *p)
{
    if (l.head == NULL)
    {
        l.head = p;
        l.tail = p;
    }
    else
    {
        p->next = l.head; // da them vao dau
        l.head = p;
    }
}
void AddTail(List &l, Node *p)
{
    if (l.head == NULL)
    {
        l.head = p;
        l.tail = p;
    }
    else
    {
        l.tail->next = p; // them vao duoc roi
        l.tail = p;       // p la nut cuoi
    }
}
void PrintList(List l)
{
    Node *p;
    p = l.head;
    while (p != NULL)
    {
        cout << p->bienso << "   ";
        p = p->next;
    }
}
int main()
{
    List l;
    l.head = NULL;
    l.tail = NULL;
    int n, x;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap bien so: ";
        cin >> x;
        Node *p = CreateNode(x);
        AddTail(l, p);
    }
    PrintList(l);
    return 0;
    
}