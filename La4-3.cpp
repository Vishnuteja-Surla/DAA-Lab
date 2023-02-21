#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    int a,b;
    cin >> a;
    cin >> b;
    int A[a];
    int B[b];
    for(int i=0; i<a; i++)
    {
        cin >> A[i];
    }
    for(int i=0; i<b; i++)
    {
        cin >> B[i];
    }
    if(a==0&&b==0)
    {
        cout << "0" << endl;
        return 0;
    }
    int C[a+b];
    int m,n;
    int count=0;
    m=0;
    n=0;
    while(m<a && n<b)
    {
        if(A[m]<B[n])
        {
            C[count]=A[m];
            count++;
            m++;
        }
        else if(A[m]>B[n])
        {
            C[count]=B[n];
            count++;
            n++;
        }
        else
        {
            C[count]=A[m];
            count++;
            m++;
            n++;
        }
    }
    while(m<a)
    {
        C[count]=A[m];
        count++;
        m++;
    }
    while(n<b)
    {
        C[count]=B[n];
        count++;
        n++;
    }
    if((count)%2!=0)
    {
        cout << C[(count)/2] << endl;
    }
    else
    {
        cout << (C[(count)/2-1]+C[(count)/2])*1.0/2 << endl;
    }
    return 0;
}
