#include <Windows.h>

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <memory>
#include <numeric>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

template <class Target, class Source>
Target narrow_cast(Source v)
{
    Target t = static_cast<Target>(v);
    if (static_cast<Source>(t) != v) {
        throw runtime_error("narrow_cast failed");
    }
    return t;
}

int main()
{
    auto c1 = narrow_cast<char>(5);
    auto c2 = narrow_cast<char>(-66);
    auto c3 = narrow_cast<char>(127);
    cout << (int)static_cast<char>(129) << std::endl;
    cout << (int)static_cast<char>(-385) << std::endl;
    return 0;
}