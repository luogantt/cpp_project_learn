#include <stdio.h>

#include "testFunc.h"

int main(void)
{    
    extern char a;    // extern variable must be declared before use
    printf("%c ", a);
    (void)msg();
    return 0;
}
