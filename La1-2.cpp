#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

    void findPair(int nums[], int n, int target)
{
    int temp[n];
    for(int i=0;i<n;i++)
        temp[i]=nums[i];
    sort(nums, nums + n);
    int px,py;
    int low = 0;
    int high = n - 1;
 
    while (low < high)
    {
        if (nums[low] + nums[high] == target)
        {
            for(int i=0;i<n;i++)
            {
                if(temp[i]==nums[high])
                    px=i;
                if(temp[i]==nums[low])
                    py=i;
            }
            if(px<py)
                cout << ""<< nums[high] << "\n" << nums[low] << "\n";
            else
                cout << ""<< nums[low] << "\n" << nums[high] << "\n";
            return;
        }
 
        (nums[low] + nums[high] < target)? low++: high--;
    }
    cout << "*";
}
 
int main()
{
    int target;
    int n;
    scanf("%d",&n);
    scanf("%d",&target);
    int nums[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&nums[i]);
    }
    
 
    findPair(nums, n, target);
 
    return 0;
}
