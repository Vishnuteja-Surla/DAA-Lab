//Greedy Logic 2 Code - Implementation of Highest denomination, Second Highest, Third Highest, ...

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int greedy(int x, int k, int d[])
{
    int count=0;
    int i=0,j=k-1;
    int rem;
    while(x>0)
    {
        rem=x-d[j];
        if(rem>=0)
        {
            count++;
            x=x-d[j];
        }
        else
        {
            j--;
        }
    }
    return count;
}

int main()
{
    int k;
    cout << "Enter number of denominations : ";
    cin >> k;
    int d[k];
    cout << "Enter the denominations :-" << endl;
    for(int i=0; i<k; i++)
    {
        cin >> d[i];
    }
    sort(d,d+k);
    int x;
    cout << "Enter the value to which we need change : ";
    cin >> x;
    int count;
    int change;
    vector<int> changes;
    int size=k;
    for(int i=0; i<k; i++)
    {
        change=greedy(x,size,d);
        changes.push_back(change);
        size--;
    }
    sort(changes.begin(),changes.end());
    count = changes[0];
    cout << "Number of coins : " << count << endl;
    return 0;
}