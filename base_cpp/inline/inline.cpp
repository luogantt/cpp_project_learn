#include <stdio.h>
 
inline const char *num_check(int v)
{
    return (v % 2 > 0) ? "奇" : "偶";
}
 
int main(void)
{
    int i;
    for (i = 0; i < 100; i++)
        printf("%02d   %s\n", i, num_check(i));
    return 0;
}
