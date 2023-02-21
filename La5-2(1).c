#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int count=0;

int Min_num(int a, int b)
{
    count++;
    if(a<=b)
        return a;
    else
        return b;
}

int Max_num(int a, int b)
{
    count++;
    if(a>=b)
        return a;
    else
        return b;
}

int max_pos(int arr[], int n)
{
    int size;
    if(n%2!=0)
    {
        size=n+1;
    }
    else
    {
        size=n;
    }
    int sum[size];
    for(int i=0; i<n; i++)
    {
        sum[i]=arr[i];
    }
    if(size>n)
    {
        sum[size-1]=arr[n-1];
    }
    int A=size/2;
    int max_sum[A];
    int k=0;
    for(int j=0; j<A; j++)
    {
        max_sum[j]=Max_num(sum[k],sum[k+1]);
        k=k+2;
    }
    int maxi_sum=max_sum[0];
    for(int j=1; j<A; j++)
    {
        maxi_sum=Max_num(maxi_sum,max_sum[j]);
    }
    
}

int main() 
{
    int n;
    scanf("%d",&n);
    int arr[n];
    int max;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int size=n*(n-1)/2;
    int sum[size];
    int i,j,k=0;
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            sum[k]=arr[i]+arr[j];
            k++;
        }
    }
    printf("%d\n",count);
    return 0;
}