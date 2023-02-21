#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    if(n==1)
    {
        cout << a[0] << endl;
        cout << 0 << endl;
        return 0;
    }
    if(n==2)
    {
        cout << "*" << endl;
        return 0;
    }
    vector <int> v;
    for(int i=1;i<n;i++)
        v.push_back(a[i]+a[0]);
    int max=v[0],count=0,index=0;
    for(int i=1;i<v.size();i++)
    {
        count++;
        if(max<v[i])
        {
            max=v[i];
            index=i;
        }
    }
    int ele=a[index+1];
    int ele1,ele2;
    ele1=ele+a[1];ele2=a[0]+a[1];
    if(ele1>ele2)
    {
        cout << ele << endl;
        cout << count+1 << endl;
    }
    else
    {
        cout << a[0] << endl;
        cout << count << endl;
    }
}