#include<bits/stdc++.h>
using namespace std;
void BubbleSort(vector<int> &arr) {
    int i, j;  
    int n = arr.size();
    for (i = 0; i < n-1; i++)      
        for (j = 0; j < n-i-1; j++)  
            if (arr[j] > arr[j+1])  
                swap(arr[j], arr[j+1]);  

}
int main()
{
    vector<int> arr = {9,3,4,1,-1,0,10,100,-3};
    BubbleSort(arr);
    cout<<"Sorted Array"<<endl;
    for(auto e:arr)
    {
        cout<<e<<" ";
    }
}