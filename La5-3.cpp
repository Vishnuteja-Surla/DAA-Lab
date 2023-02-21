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
    int i,j;
    int count=0;
    for(i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(2*arr[i]<=arr[j])
            {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}
