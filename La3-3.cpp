#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    int A,var;
    cin >> A;
    int arr[A];
    int min,max;
    for(int i=0; i<A; i++)
    {
        cin >> var;
        arr[i]=var;
        if(i==0)
        {
            min=var;
            max=var;
        }
        else
        {
            if(var<=min)
            {
                min=var;
            }
            if(var>=max)
            {
                max=var;
            }
        }
    }
    cout << min << endl;
    cout << max << endl;
    return 0;
}
