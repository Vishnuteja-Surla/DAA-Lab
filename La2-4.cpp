#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void asc_sort(int a[],int size)
{
    int temp;
    for(int i=0;i<size-1;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    for(int i=0;i<size;i++)
        cout << a[i] << endl;
}

int main() 
{
    int max_size=8888;
    int k;
    cin >> k;
    int arr_size[k];
    int arr[max_size];
    int count = 0;
    for(int i=0; i<k; i++)
    {
        cin >> arr_size[i];
        for(int j=0; j<arr_size[i]; j++)
        {
            int p;
            cin >> p;
            arr[count] = p;
            count++;
        }
    }
    asc_sort(arr,count);
    return 0;
}