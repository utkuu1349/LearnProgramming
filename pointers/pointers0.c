#include <stdio.h>

int main ()
{
    int x;
    int *p;

    p = (pointer)0xFFFFF12;
    //scanf("%d", &x);
    printf("%d\n", *p);
    getchar();    	
}
