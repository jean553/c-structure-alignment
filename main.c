#include <stdio.h>

struct NotAligned {
    char one;
    int two;
};

struct Aligned {
    char one;
    char two;
};

struct OtherAligned {
    int one;
    char two, three, four, five;
};

struct NotOptimized {
    char one;
    int two;
    char three;
};

struct Optimized {
    char one;
    char three;
    int two;
};

int main()
{
    struct NotAligned value;
    struct Aligned other;
    struct OtherAligned another;
    struct NotOptimized notOptimized;
    struct Optimized optimized;

    return 0;
}
