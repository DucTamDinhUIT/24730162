#include <iostream>
#include <string>
#include "sinhvien.hpp"
using namespace std;
class CaoDang : public SinhVien
{
private:
    float thiTN;
public:
    CaoDang(/* args */);
    ~CaoDang();
    void nhapCD();
    bool xetTNCaoDang();
};

