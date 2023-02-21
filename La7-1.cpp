#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    int T;
    cin >> T;
    for(int iter=0; iter<T; iter++)
    {
        int n,m,C;
        cin >> n >> m >> C;
        int teams[C];
        for(int i=0; i<C; i++)
        {
            cin >> teams[i];
        }
        vector<int> rooms;
        for(int i=0; i<C; i++)
        {
            for(int j=0; j<teams[i]; j++)
            {
                rooms.push_back(i+1);
            }
        }
        int room[n][m];
        int vi=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                room[i][j]=rooms[vi];
                vi++;
            }
        }
        for(int i=0; i<n; i++)
        {
            if(i%2==0)
            {
                for(int j=0; j<m; j++)
                {
                    cout << room[i][j] << " ";
                }
            }
            else
            {
                for(int j=m-1; j>=0; j--)
                {
                    cout << room[i][j] << " ";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}
