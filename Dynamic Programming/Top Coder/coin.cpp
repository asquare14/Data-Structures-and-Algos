#include <iostream>
using namespace std;
int main()
{
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int sum; cin>>sum;
    int min_arr[sum+1];
    min_arr[0]=0;

    for(int i=1;i<=sum;i++)
        min_arr[i] = INT_MAX;

    for(int i=1;i<=sum;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[j]<=i && min_arr[i-arr[j]]+1<min_arr[i])
            {
                min_arr[i] = min_arr[i-arr[j]]+1;
            }
        }
    }

    cout<<min_arr[sum];
}