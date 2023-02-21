//Greedy Logic 1 Code - Implementation of Highest denomination takes highest number of coins

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

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
    int count=0;
    int i=0,j=k-1;
    int rem;
    vector<int> coins;
    while(x>0)
    {
        rem=x-d[j];
        if(rem>=0)
        {
            coins.push_back(d[j]);
            count++;
            x=x-d[j];
        }
        else
        {
            j--;
        }
    }
    cout << "Number of coins : " << count << endl;
    cout << "Coins : ";
    for(i=0; i<coins.size();i++)
    {
        cout << coins[i] << " ";
    }
    cout << "\n";
    return 0;
}