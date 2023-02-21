#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    float ans=log10(n)/log10(3);
    printf("%.4f",ans);
    return 0;
}
