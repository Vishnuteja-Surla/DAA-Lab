#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int p=0;
    vector<int>vec;
    int j=0,m=0;
    while(1)
    {
        if(m==n-j-1)
        {
            vec.insert(vec.begin()+p,a[m]);
            break;
        }
        else if(a[m]==a[n-j-1])
        {
            vec.insert(vec.begin()+p,a[m]);
            vec.insert(vec.begin()+p+1,a[m]);
            p++;
        }
        else if(m>n-j-1)
        {
            break;
        }
        else{
            if(a[m]+a[m+1]==a[n-j-1] && a[m]!=0 && a[m+1]!=0)
            {
                vec.insert(vec.begin()+p,a[n-j-1]);
                vec.insert(vec.begin()+p+1,a[n-j-1]);
                p++;
                m++;
            }
            else if(a[m]==a[n-j-1]+a[n-j-2] && a[n-j-1]!=0 && a[n-j-2]!=0)
            {
                vec.insert(vec.begin()+p,a[m]);
                vec.insert(vec.begin()+p+1,a[m]);
                p++;
                j++;
            }
            else if(a[m]+a[n-j-1]==a[m])
            {
                vec.insert(vec.begin()+p,a[m]);
                p++;
            }
            else if(a[m]+a[n-j-1]==a[n-j-1])
            {
                vec.insert(vec.begin()+p,a[n-j-1]);
                p++;
            }
            else if(vec.size()!=0){
            if(n-j-1-m==1 && a[m]!=a[n-j-1])
            {
                vec.insert(vec.begin()+p,a[m]+a[m+1]);
                p++;
            }
            else if(n-j-1-m==1 && a[m]==a[n-j-1])
            {
                vec.insert(vec.begin()+p,a[m]);
                vec.insert(vec.begin()+p,a[n-j-1]);
                p++;
            }
            }
            else
            {
                break;
            }
        }
        m++;
        j++;
    }
    if(vec.size()==0)
    {
        cout<<"*";
        return 0;
    }
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<endl;
    }
    return 0; 
}
