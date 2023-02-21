#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void find_minimum(int n, int *arr)
{
    int temp;
    int min=arr[0];
    int s_min;
    int i=1;
    if(n==1)
    {
        cout << min << endl;
        cout << "*" << endl;
        return ;
    }
    for(i=1; i<n; i++)
    {
        if(min!=arr[i])
        {
            s_min=arr[i];
            break;
        }
    }
    if(i==n)
    {
        cout << min << endl;
        cout << "*"  << endl;
        return ;
    }
    if(min>s_min)
    {
        temp=min;
        min=s_min;
        s_min=temp;
    }
    for(i=1; i<n; i++)
    {
        if(arr[i]<min)
        {
            s_min=min;
            min=arr[i];
        }
        else if(min<arr[i]&&s_min>arr[i])
        {
            s_min=arr[i];
        }
        else
        {
            continue;
        }
    }
    cout << min << endl;
    cout << s_min  << endl;
}

int main() 
{
    int A;
    cin >> A;
    int arr[A];
    for(int i=0; i<A; i++)
    {
        cin >> arr[i];
    }
    find_minimum(A,arr);
    return 0;
}
