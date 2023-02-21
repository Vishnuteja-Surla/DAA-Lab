#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a_sum(int arr[],int A)
{
    int sum=0;
    for(int i=0; i<A; i++)
    {
        sum=sum+arr[i];
    }
    return(sum);
}

int main() 
{
    int A,k;
    cin >> A;
    cin >> k;
    int arr[A];
    for(int i=0; i<A; i++)
    {
        cin >> arr[i];
    }
    if(A==1&&arr[0]!=k)
    {
        cout << "*" << endl;
        return(0);
    }
    if(A==1&&arr[0]==k)
    {
        cout << "1" << endl;
        cout << arr[0] << endl;
        return 0;
    }
    int sum;
    sum=a_sum(arr,A);
    int a,b;
    a=0; b=0;
    for(int i=0; i<A; i++)
    {
        int j;
        a=a+arr[i];
        if(abs(2*a-sum)==k)
        {
            cout << "1" << endl;
            for(j=0; j<=i; j++)
            {
                cout << arr[j] << endl;
            }
            cout << "2" << endl;
            for(;j<A;j++)
            {
                cout << arr[j] << endl;
            }
            return 0;
        }
    }
    cout << "*" << endl;
    return 0;
}
