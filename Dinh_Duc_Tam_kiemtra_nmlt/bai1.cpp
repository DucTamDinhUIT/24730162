// BÀI TẬP BẮT BUỘC: CHUỖI KÝ TỰ
// 1. Viết hàm kiểm tra chuỗi chuoi có đối xứng không, hàm trả về 1 nếu chuỗi đối xứng, trả
// về 0 nếu chuỗi không đối xứng. Ví dụ: chuỗi “abcdcba” là đối xứng, chuỗi “abcdxya”
// là không đối xứng.
// 2. Tính độ dài chuỗi
// 3. Đảo ngược các kí tự trong chuỗi
// 1. Tìm vị trí kí tự xuất hiện đầu tiên trong chuỗi
// 2. Tìm vị trí xuất hiện của kí tự c trong chuỗi s
// 3. Tìm chuỗi con trong 1 chuỗi
// 4. Thay thế kí tự trong chuỗi
// 5. Đếm số lần xuất hiện của kí tự c trong chuỗi s
// 6. Thay thế kí tự bất kì trong chuỗi bằng kí tự mới
// 7. Xuất các ký tự in hoa trong chuỗi
// 8. Đổi chữ xen kẻ 1 chữ hoa và 1 chữ thường.
// 9. Đếm một ký tự xuất hiện bao nhiêu lần trong chuỗi.
// 10.Tìm kiếm xem ký tự nào xuất nhiện nhiều nhất trong chuỗi.
// 11.Nhập vào một từ và xoá từ đó trong chuỗi đã cho.

#include <iostream>
#include <string>

using namespace std;

// kiem tra chuoi doi xung
bool doiXung(const string &chuoi)
{
    int n = chuoi.length();
    for (int i = 0; i < n / 2; ++i)
    {
        if (chuoi[i] != chuoi[n - 1 - i])
            return false;
    }
    return true;
}

// 2 do dai chuoi
int length(const string &chuoi)
{
    int len = 0;
    for (int i = 0; i < chuoi.length(); i++)
    {
        ++len;
    }
    return len;
}

// 3 dao nguoc chuoi
string daoChuoi(const string &chuoi)
{
    string reversed = chuoi;
    int n = reversed.length();
    for (int i = 0; i < n / 2; ++i)
    {
        swap(reversed[i], reversed[n - 1 - i]);
    }
    return reversed;
}

// 4 tim vi tri ky tu dau
int timKiTuDauTien(const string &chuoi, char c)
{
    return chuoi.find(c);
}

// 5 tim vi tri ca cac ki tu
void timVitriAll(const string &chuoi, char c)
{
    for (int i = 0; i < chuoi.length(); ++i)
    {
        if (chuoi[i] == c)
        {
            cout << "Cac vi tri gom: " << i << endl;
        }
    }
}

// 6. tim chuoi con
int findSubstring(const string &chuoi, const string &sub)
{
    return chuoi.find(sub);
}

// 7 thay the k
string replaceChar(string chuoi, char oldChar, char newChar)
{
    for (char &ch : chuoi)
    {
        if (ch == oldChar)
            ch = newChar;
    }
    return chuoi;
}

// 8. Đếm số lần xuất hiện của kí tự c
int countChar(const string &chuoi, char c)
{
    int count = 0;
    for (char ch : chuoi)
    {
        if (ch == c)
            ++count;
    }
    return count;
}

// 9. Thay thế tất cả ký tự bất kỳ bằng ký tự mới
string replaceAll(string chuoi, char target, char newChar)
{
    return replaceChar(chuoi, target, newChar); // dùng lại hàm 7
}

// 10. Xuất các ký tự in hoa
void printUppercaseChars(const string &chuoi)
{
    for (int i = 0; i < chuoi.length(); ++i)
    {
        char ch = chuoi[i];
        if (isupper(ch))
            cout << ch << " ";
    }
    cout << endl;
}

// 11. Đổi chữ xen kẽ: chữ hoa - chữ thường
string alternateCase(string chuoi)
{
    for (int i = 0; i < chuoi.length(); ++i)
    {
        if (i % 2 == 0)
            chuoi[i] = toupper(chuoi[i]);
        else
            chuoi[i] = tolower(chuoi[i]);
    }
    return chuoi;
}

// // 12. Tìm ký tự xuất hiện nhiều nhất
// char mostFrequentChar(const string &chuoi)
// {
//     unordered_map<char, int> freq;
//     for (char ch : st)
//     {
//         ++freq[ch];
//     }
//     char maxChar = 0;
//     int maxCount = 0;
//     for (auto &p : freq)
//     {
//         if (p.second > maxCount)
//         {
//             maxCount = p.second;
//             maxChar = p.first;
//         }
//     }
//     return maxChar;
// }

// 13. xoa tu  khoi chuoi
string xoaTu(string chuoi, const string &word)
{
    size_t pos = chuoi.find(word);
    while (pos != string::npos)
    {
        chuoi.erase(pos, word.length());
        pos = chuoi.find(word);
    }
    return chuoi;
}

// === Main để test ===
int main()
{
    string s;
    cout << "nhap chuoi ky tu: ";
    //cin.ignore();
    getline(cin, s);

    if (doiXung(s))
    {
        cout << "Chuoi doi xung" << endl;
    }
    else
    {
        cout << "Chuoi khong doi xung" << endl;
    }

    cout << "do dai chuoi: " << length(s) << endl;

    cout << "dao nguoc chuoi: " << daoChuoi(s) << endl;
    cout << "nhap ki tu can tim: ";
    char c;
    cin >> c;
    cout << "vi tri ki tu " << c << " dau tien: " << timKiTuDauTien(s, c) << endl;
    cout << "All positions of '" << c << "':\n";
    
    timVitriAll(s, c);

    string sub = "abc";
    cout << "Substring '" << sub << "' found at: " << findSubstring(s, sub) << endl;

    cout << "thay doi ky tu: " << replaceChar(s, 'a', 'x') << endl;

    cout << "dem ky tu: " << countChar(s, 'v') << endl;

    cout << "thay tat ca ky tu: " << replaceAll(s, 'a', 'v') << endl;

    cout << "in hoa ky tu: ";
    printUppercaseChars(s);

    cout << "doi: " << alternateCase(s) << endl;

   // cout << "Most frequent char: " << mostFrequentChar("abcabcabz") << endl;

    cout << "Loai bo chuoi: " << xoaTu(s, "abc") << endl;

    return 0;
}
