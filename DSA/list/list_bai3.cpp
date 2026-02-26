#include <iostream>
using namespace std;

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

Node *CreateNode(int x)
{
    Node *p;
    p = new Node;
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
        p->next = l.head;
        l.head = p;
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
    int x, n;
    cout << "nhap so luong phan tu: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "nhap bien so: ";
        cin >> x;
        Node *p = CreateNode(x);
        AddHead(l, p);
    }
    PrintList(l);
    return 0;
}
