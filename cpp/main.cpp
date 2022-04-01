#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <cstdio>
#include <sstream>
#include "utils.h"

using namespace std;

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
    set<int> lis {1,2,3,4,5};
    cout << lis << endl;

    map<string, int> m = {{"gerike", 6}};
    //stringstream ss;
    //for(auto& v : m) {
        //ss << v.first << ":" << v.second;
    //}
    //cout << ss.str();
    cout << m;

    return 0;
}
