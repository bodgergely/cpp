#include <cassert>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <sstream>
#include <string_view>
#include <vector>

#include "helper.h"

using namespace std;

namespace
{
int func(int v) { return v * 2; }

}  // namespace

class Foo
{
public:
    Foo();

    ~Foo();

protected:
    void swim();

private:
    int v;
};

int main()
{
    switch (5) {
    case 1: {
        6;
        break;
    }
    default:
        break;
    }

    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';

    cout << func(3) << '\n';

    return 0;
}