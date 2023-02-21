#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void heapify(int arr[], int n, int i) 
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
  
    if (left<n && arr[left]>arr[largest])
      largest = left;
  
    if (right<n && arr[right]>arr[largest])
      largest = right;
    if (largest!= i) 
    {
      swap(arr[i], arr[largest]);
      heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) 
{
    for (int i=n/2-1; i>=0; i--)
      heapify(arr,n,i);
    for (int i=n-1; i>=0; i--) 
    {
      swap(arr[0], arr[i]);
      heapify(arr,i,0);
    }
}

int main() 
{
    int n,m;
    cin >> m;
    cin >> n;
    int arr[m][n];
    int dummy[m];
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> arr[i][j];
        }
    }
    for(int i=0; i<m; i++)
    {
        heapSort(arr[i],n);
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            dummy[j]=arr[j][i];
        }
        heapSort(dummy,m);
        for(int j=0; j<m; j++)
        {
            arr[j][i]=dummy[j];
        }
    }
    cout << arr[0][0] << endl;
    cout << arr[m-1][n-1] << endl;
    return 0;
}
