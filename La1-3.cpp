#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

void findPair(int nums[], int n, int target)
{
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        if (map.find(target - nums[i]) != map.end())
        {
            cout << nums[map[target - nums[i]]] << "\n" << nums[i] << "\n";
            return;
        }
        map[nums[i]] = i;
    }
    cout << "*";
}
 
int main()
{
    int n,z;
    cin >> n >> z;
    int i,nums[n];
    for(i=0;i<n;i++)
        cin >> nums[i];
    findPair(nums, n, z);
    return 0;
}