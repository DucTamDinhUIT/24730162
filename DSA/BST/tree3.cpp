#include <iostream>
using namespace std;
struct Tree
{
    int key;
    Tree * left, * right;
};

Tree * Create(int key){
    Tree *p = new Tree;
    p->key = key;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insert(Tree *&p, int key){
    if (p = NULL)
    {
        Create(key);
    }
    else
    {
        if (key < p->key)
        {
            insert(p->left, key);
        }
        else
        {
            insert(p->right, key);
        }
        
    }
    
}
int main()
{
    int a;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        int x;
        cin >> x;
        Create(x);
    }
    
}