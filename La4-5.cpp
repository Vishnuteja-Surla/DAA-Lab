#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int three_way_Search(int array[], int x, int low, int high) 
{
    if (high >= low) 
    {
        int third1 = low+(high - low)/3;
        int third2 = third1+(high-low)/3;
        if(array[third1] == x)
            return third1;
        if(array[third2] == x)
            return third2;
        if(array[third1] > x)
            return three_way_Search(array,x,low,third1 - 1);
        if(array[third2] > x)
            return three_way_Search(array,x,third1,third2 - 1);
        return three_way_Search(array,x,third2+1,high);
    }
    return -1;
}

int main() 
{
    int n,x;
    cin >> n;
    cin >> x;
    int arr[n];
    int i;
    for(i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    int result = three_way_Search(arr,x,0,n-1);
    if(result==-1)
        cout << "0" << endl;
    else
        cout << "1" << endl;
    return 0;
}
