#include <iostream>
using namespace std;

struct TREE {
    int value;
    TREE * pLeft;
    TREE * pRight;
}

void NLR(TREE root)
{
    if (Root != NULL)
    {
        <root>; // xử lý tương ứn
        NLE(Root->pLeft);
        NLE(Root->pRight);
    }
}
