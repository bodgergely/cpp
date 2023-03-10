#include <stdio.h>

/*
 * Prove that 0.1 + 0.2 = 0.3
 */

int main(int argc, char** argv)
{
    double a = 0.1;
    double b = 0.2;
    double sum = a + b;
    double theo = 0.3;
    double diff = sum - theo;
    printf("%0.17f == %0.17f with diff %0.30f is %d\n", sum, theo, diff,
           (sum == theo));
    printf("diff is null: %d, diff from null: %0.30f\n", diff == 0.0,
           diff - 0.0);

    double expected = 1000.0;
    double real = 0.0;
    for (int i = 0; i < 100000; i++) {
        real += 0.01;
    }

    printf("expected: %0.17f, reality: %0.17f, diff: %0.17f\n", expected, real,
           real - expected);

    return 0;
}
