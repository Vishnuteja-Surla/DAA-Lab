#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    int A;
    cin >> A;
    int min,s_min;
    int arr[A];
    int i;
    for(i=0; i<A; i++)
    {
        cin >> arr[i];
    }
    sort(arr,arr+A);
    min=arr[0];
    i=0;
    if(A==1)
    {
        cout << min << endl;
        cout << "*" << endl;
    }
    else
    {
        while(i<A)
        {
            if(min!=arr[i])
            {
                s_min=arr[i];
                break;
            }
            i++;
        }
        if(i==A)
        {
            cout << min << endl;
            cout << "*" << endl;
        }
        else
        {
            cout << min << endl;
            cout << s_min << endl;
        }
    }
    return 0;
}