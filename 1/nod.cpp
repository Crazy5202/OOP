#include "nod.hpp"

int nod(int a, int b) {
    a=std::abs(a);
    b=std::abs(b);
    while ((a != 0) and (b != 0)) {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    return (a + b);
}