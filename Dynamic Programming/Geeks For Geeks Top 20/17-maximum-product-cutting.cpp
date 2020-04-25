#include<bits/stdc++.h>
using namespace std;

// int integerBreak(int n) {
//         if(n==2) return 1;
//         if(n==3) return 2;
//         if(n==4) return 4;
//         int res = 1; 
//         while (n > 4) 
//         { 
//                n -= 3; 
//                res *= 3; // Keep multiplying 3 to res 
//         } 
//        return (n * res);
// }

int integerBreak(int n) {
   int val[n+1]; 
   val[0] = val[1] = 0; 
   
   for (int i = 1; i <= n; i++) 
   { 
      int max_val = 0; 
      for (int j = 1; j <= i/2; j++) 
      {
          int t = max( j*val[i-j],(i-j)*j);
          max_val = max(max_val,t); 
      
      }
      val[i] = max_val; 
   } 
   return val[n];
}


int main()
{
    int n; cin>>n;
    cout<<integerBreak(n);
}