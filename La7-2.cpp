#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    int n;
    cin>>n;
    int marks[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>marks[i];
        sum+=marks[i];
    }
    if(sum%2!=0)
    {
        cout<<"NO";
        return 0;
    }
    int big_sum[n+1] = { 0 };
    for (int i = 0; i < n; i++)
        big_sum[i+1] = big_sum[i] + marks[i];
    vector<int> s_array;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            s_array.push_back(big_sum[j] - big_sum[i-1]);
    for(int i=0;i<s_array.size();i++)
    {
        if(s_array[i]==(sum/2))
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    
    
    return 0;
}