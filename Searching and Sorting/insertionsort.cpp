#include<bits/stdc++.h>
using namespace std;
void InsertionSort(vector<int> &arr) {
    for (int i = 1; i < arr.size(); i++) 
    {  
        int key = arr[i];  
        int j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  

}
int main()
{
    vector<int> arr = {9,3,4,1,-1,0,10,100,-3};
    InsertionSort(arr);
    cout<<"Sorted Array"<<endl;
    for(auto e:arr)
    {
        cout<<e<<" ";
    }
}