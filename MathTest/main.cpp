#include <iostream>
#include "mathtest.h"
int main() {
    MathTest test(5, 1, 20, '+');
    test.run();
    MathTest test2(5, 1, 20);
    test2.run();
    return 0;
}