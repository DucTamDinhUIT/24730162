#include <iostream>
using namespace std;

struct tagNode
{
    int Key;
    struct tagNode *Left, *Right;
};
tagNode *CreateNode(int Key)
{
    tagNode *p = new tagNode;
    p->Key = Key;
    p->Left = NULL;
    p->Right = NULL;
    return p;
}
void InsertNode(tagNode *&T, int Key)
{
    if (T == NULL)
    {
        T = CreateNode(Key);
    }
    else
    {
        if (Key < T->Key)
            InsertNode(T->Left, Key);
        else
            InsertNode(T->Right, Key);
    }
}
void PreOrder(tagNode *T)
{
    if (T != NULL)
    {
        cout << T->Key << " ";
        PreOrder(T->Left);
        PreOrder(T->Right);
    }
}

void deleteNode(tagNode *&T, int Key)
{
    if (T == NULL)
        return;
    if (Key < T->Key)
        deleteNode(T->Left, Key);
    else if (Key > T->Key)
        deleteNode(T->Right, Key);
    else
    {
        if (T->Left == NULL)
        {
            tagNode *temp = T;
            T = T->Right;
            delete temp;
        }
        else if (T->Right == NULL)
        {
            tagNode *temp = T;
            T = T->Left;
            delete temp;
        }
        else
        {
            tagNode *temp = T->Right;
            while (temp && temp->Left != NULL)
                temp = temp->Left;
            T->Key = temp->Key;
            deleteNode(T->Right, temp->Key);
        }
    }
}
int main()
{
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    tagNode *T = NULL;
    cout << "Nhap cac phan tu: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        InsertNode(T, x);
    }
    PreOrder(T);
    deleteNode(T, 5);
    cout << "Duyet cay theo PreOrder: ";
    PreOrder(T);
    cout << endl;
}