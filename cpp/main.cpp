#include <algorithm>
#include <atomic>
#include <cassert>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <thread>
#include <unordered_set>
#include <vector>

using u8 = uint8_t;

using namespace std;

//string bin(void* data, int count)
//{
//    string res{""};
//    u8* c = (u8*)data;
//    for (int i = 0; i < count; i++) {
//        u8 byte = *(c + i);
//        for (int j = 0; j < 8; j++) {
//            if ((byte << j) & 0x80) {
//                res.push_back('1');
//            }
//            else {
//                res.push_back('0');
//            }
//        }
//        res.push_back(' ');
//    }
//    res.pop_back();
//    return res;
//}

int main()
{
    // double a = 1.2;
    // double b = 1.0;
    // double h = a - b;
    //double h = 0.1;
    //// printf("%f\n", h);
    //cout << bin((void*)&h, sizeof(h)) << endl;
    int res = 0x66666666;
    res = 0x0;
    char* pres = (char*)&res;
    *(pres + 0) = 0xDE;
    *(pres + 1) = 0xAD;
    *(pres + 2) = 0xBE;
    *(pres + 3) = 0xEF;

    cout << res << endl;

    return res;
}
