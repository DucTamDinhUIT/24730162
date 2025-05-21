#include <iostream>
#include <string>
#include "sinhvien.hpp"
using namespace std;
class DaiHoc : public SinhVien
{
private:
    string tenLv;
    float diemLV;

public:
    DaiHoc(/* args */);
    ~DaiHoc();
};
