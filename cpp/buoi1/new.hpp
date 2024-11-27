#include <iostream>
using namespace std;
class tamgiac
{
private:
    /* data */
    int dai, rong, cao;
public:
    tamgiac(/* args */);
    ~tamgiac();
    void nhap();
    void xuat();
};

tamgiac::tamgiac(/* args */)
{
}

tamgiac::~tamgiac()
{
}

void tamgiac::nhap()
{
    cout << "nhap dai rong cao tam giac" << endl;
    cin >> dai >> rong >> cao;
}

void tamgiac::xuat()
{
    cout << "dai: " << dai << "rong: " << rong << "cao: " << cao << endl;
}
