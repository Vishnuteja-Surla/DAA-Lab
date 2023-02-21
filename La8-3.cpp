//Coin Change Problem using Dynamic Programming

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minimum(int k, int arr[])
{
    int min;
    min=arr[0];
    for(int i=0; i<k-1; i++)
    {
        if(min>=arr[i+1])
        {
            min=arr[i+1];
        }
    }
    return min;
}

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

int dynamic(int x, int k, int d[])
{
    int change[x];
    int count;
    for(int i=0; i<d[k-1]; i++)
    {
        count = greedy(i+1,k,d);
        change[i] = count;
    }
    int dp_array[k];
    for(int i=d[k-1]+1; i<=x; i++)
    {
        for(int j=0; j<k; j++)
        {
            int pos = i-d[j];
            dp_array[j] = change[pos-1];
        }
        count = 1 + minimum(k,dp_array);
        change[i-1] = count;
    }
    return change[x-1];
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
    count=dynamic(x,k,d);
    cout << "Number of coins : " << count << endl;
    return 0;
}