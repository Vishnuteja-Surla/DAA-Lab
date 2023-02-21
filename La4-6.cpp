#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    int arr[n];
    int sarr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sarr[i] = arr[i];
    }
    if(n == 1)
    {
        cout << "*" << endl;
        return 0;
    }
    sort(sarr,sarr+n);
    int flag = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] != sarr[i])
        {
            flag = 1;
        }
    }
    if(flag == 0)
    {
        cout << "*" << endl;
        return 0;
    }
    int start = 0;
    int end = 0;
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        if(sarr[i] != arr[i])
        {
            if(count == 0)
            {
                start = i;
                count = 1;
            }
            else
            {
                end = i;
            }
        }
    }
    cout << start << endl;
    cout << end << endl;
    return 0;
}
