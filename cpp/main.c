#include <stdio.h>

int main(int argc, char** argv)
{
    long long r8 = 0x2535D4C292F8BE76;
    r8 -= 0x199730612B613F85;
    printf("%llx", r8);
    return 0;
}

