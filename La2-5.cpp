#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;

void binarySearch(int arr[], int low, int high)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;
        if (mid == arr[mid])
            vec.push_back(mid);           
        if (mid + 1 <= arr[high])
            binarySearch(arr, (mid + 1), high);
        if (mid - 1 >= arr[low])
            binarySearch(arr, low, (mid - 1));
    }
}

int main()
{
    int size;
    cin >> size;
    int arr[size];
    for(int i=0;i<size;i++)
        cin >> arr[i];
    binarySearch(arr,0,size-1);
    if(vec.size() == 0)
    {
        cout << "*" << endl;
        return 0;
    }
    sort(vec.begin(),vec.end());
    for(int i : vec)
        cout << i << endl;
}