#include <iostream>
using namespace std;
int main()
{
    int t;cin>>t;
    while(t--){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    int lis[n];
    for(int i=0;i<n;i++) lis[i]=1;
    lis[0]=1;

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]<arr[j] && lis[i]+1>lis[j])
                lis[j] = lis[i]+1;
        }
    }

    int ans = 1;
    for(int i=0;i<n;i++)
        ans = max(ans,lis[i]);
    cout<<ans<<endl;

    }
    return  0;
}