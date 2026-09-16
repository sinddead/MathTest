#include <iostream>
#include "mathtest.h"
int main() {
    MathTest test(10, -2, 3);
    test.run();
    test.show_statistics();
    return 0;
}