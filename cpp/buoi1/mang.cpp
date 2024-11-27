#include <iostream>
using namespace std;
void nhapmang(int A[], int n){
    for (int i = 0; i<n; i++){
        cout << "Nhap phan thu thu " << i << ": ";
        cin >> A[i];
    }
}

void xuatmang(int A[], int n){
    for (int i = 0; i<n; i++){
        cout << "A" << i << ": " << A[i] << endl;
    }
}
int main(){
    int B[20];
    nhapmang(B, 5);
    xuatmang(B, 5);
}