#include <stdio.h>
#include <sys/types.h>

int main()
{
    u_int8_t i, sbuf=0;
    for(i=0;i<8;i++)
    {
        sbuf <<=1;
        printf("%d\n", sbuf);
        sbuf|=1;
        printf("%d\n", sbuf);
    }
    return 0;
}