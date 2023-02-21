#include<bits/stdc++.h>
using namespace std;
int coinchange(vector<int>a,int n,int k,int b[])
{
    vector<int>vec;
    for(int i=k-1;i>=0;i--)
    {
        while(n>=a[i])
        {
            if(b[i]=0)
                break;
            n-=a[i];
            b[i]--;
            vec.push_back(a[i]);
        }
    }
    if(n!=0)
    {
        return -1;
    }
    return (vec.size());
}
int main()
{
    int n,k;
    cout<<"enter the value :";
    cin>>n;
    cout<<"enter no of denominations :";
    cin>>k;
    int b[k];
    vector<int>a;
    cout<<"enter the denominations :";
    for(int i=0;i<k;i++)
    {
        cin>>b[i];
        a.push_back(b[i]);
    }
    sort(a.begin(),a.end());
    int pos=a.size();
    int x=k;
    vector<int>c;
    cout<<"enter the no of coins :";
    int m[k];
    for(int i=0;i<k;i++)
    {
        cin>>m[i];
    }
    for(int i=0;i<x;i++)
    {
        int y=coinchange(a,n,k,b);
        c.push_back(y);
        k--;
    }
    sort(c.begin(),c.end());
    int j,q=0;
    for(j=0;j<c.size();j++)
    {
        if(c[j]!=-1)
        {
            q++;
            break;
        }
    }
    if(q!=0)
        cout<<"minimum no of coins : "<<c[j];
    else
        cout<<"NOT possible"<<endl;
    return 0;
}