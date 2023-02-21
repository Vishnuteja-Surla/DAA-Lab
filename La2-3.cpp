#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    int k;
    cin >> k;
    int n;
    int temp;
    vector <int> vec;
    for(int i=0; i<k; i++)
    {
        cin >> n;
        for(int j=0; j<n; j++)
        {
            cin >> temp;
            vec.push_back(temp);
        }
    }
    sort(vec.begin(),vec.end());
    for(int i=0; i<vec.size(); i++)
    {
        cout << vec[i] << endl;
    }
    return 0;
}
