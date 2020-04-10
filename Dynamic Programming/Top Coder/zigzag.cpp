#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t; cin>>t;

    while(t--){
    int n; cin>>n;
    int v[n];
    for(int i=0;i<n;i++) cin>>v[i];

    vector <int> arr;

    arr.push_back(v[0]);

    for(int i=1;i<n;i++)
    {
        if(v[i]!=v[i-1])
            arr.push_back(v[i]);
    }

    n = arr.size();

    if(n==0)
    {
        cout<<0<<endl;
        continue;
    }
    if(n==1)
    {
        cout<<1<<endl;
        continue;
    }
    if(n==2)
    {
        cout<<2<<endl;
        continue;
    }

    int b[n];

    for(int i=0;i<n;i++)
    {
        b[i]=0;
    }

    if(arr[0]-arr[1]>0) b[0]=1;

    int  c  = 1;
    for(int i=1;i<n-1;i++)
    {
        if(arr[i]-arr[i+1]>0) b[i] = 1;
        if(b[i]!=b[i-1])
            c++;
    }
    cout<<c+1<<endl;
    }

    return 0;
}