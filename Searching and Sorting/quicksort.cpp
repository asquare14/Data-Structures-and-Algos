#include<bits/stdc++.h>
using namespace std;
int partition (vector<int> &arr, int low, int high)  
{  
    int pivot = arr[high]; // pivot  
    int i = low; // Index of smaller element  
    int j = high;
    while(i<j)
    {
        while(arr[i]<=pivot)
        {
            i++;
        }
        while(arr[j]>pivot)
        {
            j--;
        }
        if(i<j)
            swap(arr[i],arr[j]);

    }
    swap(arr[low],arr[j]);
    return j;  
}  

void QuickSort(vector<int> &arr,int l,int h)
{
    if(l<h) {
        int  j = partition(arr,l,h);
        QuickSort(arr,l,j);
        QuickSort(arr,j+1,h);
    }
}
int main()
{
    vector<int> arr = {9,3,4,1,-1,0,10,100,-3};
    QuickSort(arr,0,arr.size()-1);
    cout<<"Sorted Array"<<endl;
    for(auto e:arr)
    {
        cout<<e<<" ";
    }
}