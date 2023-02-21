#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n,x,y=-2098,z;
    scanf("%d",&n);
    int arr[n];
    scanf("%d",&z);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0; i<n; i++)
    {
        x=arr[i];
        for(int j=i; j<n; j++)
        {
            if(arr[j]==z-x)
            {
                y=arr[j];
                break;
            }
        }
        if(y!=-2098)
        {
            break;
        }
    }
    if(y==-2098)
    printf("*");
    else
    printf("%d\n%d",x,y);
    return 0;
}
