#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int Min_num(int a, int b)
{
    if(a<=b)
        return a;
    else
        return b;
}

int Max_num(int a, int b)
{
    if(a>=b)
        return a;
    else
        return b;
}

int main() 
{
    int A,n;
    cin >> A;
    if(A%2!=0)
    {
        n=A+1;
    }
    else
    {
        n=A;
    }
    int arr[n];
    for(int i=0; i<A; i++)
    {
        cin >> arr[i];
    }
    if(n==A+1)
    {
        arr[n-1]=arr[A-1];
    }
    int size=n/2;
    int min[size];
    int max[size];
    int i=0;
    for(int j=0; j<size; j++)
    {
        min[j]=Min_num(arr[i],arr[i+1]);
        max[j]=Max_num(arr[i],arr[i+1]);
        i=i+2;
    }
    int mini=min[0];
    int maxi=max[0];
    for(int j=1; j<size; j++)
    {
        mini=Min_num(mini,min[j]);
        maxi=Max_num(maxi,max[j]);
    }
    cout << mini << endl;
    cout << maxi << endl;
    return 0;
}
