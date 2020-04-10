#include<bits/stdc++.h>
using namespace std;
int count(vector<char> &sy,vector<char> &op)
{
    int n = sy.size();
    int t[n][n], f[n][n];

    for(int i=0;i<n;i++)
    {
        if(sy[i]=='T')
            t[i][i] = 1;
        else t[i][i] = 0;
        
        if(sy[i]=='F')
            f[i][i] = 1;
        else f[i][i] = 0;
    }
    for (int gap=1; gap<n; ++gap) 
    { 
        for (int i=0, j=gap; j<n; ++i, ++j) 
        { 
            t[i][j] = f[i][j] = 0; 
            for (int g=0; g<gap; g++) 
            { 
                int k = i + g; 
                int tik = t[i][k] + f[i][k]; 
                int tkj = t[k+1][j] + f[k+1][j]; 
  
                if (op[k] == '&') 
                { 
                    t[i][j] += t[i][k]*t[k+1][j]; 
                    f[i][j] += (tik*tkj - t[i][k]*t[k+1][j]); 
                } 
                if (op[k] == '|') 
                { 
                    f[i][j] += f[i][k]*f[k+1][j]; 
                    t[i][j] += (tik*tkj - f[i][k]*f[k+1][j]); 
                } 
                if (op[k] == '^') 
                { 
                    t[i][j] += f[i][k]*t[k+1][j] + t[i][k]*f[k+1][j]; 
                    f[i][j] += t[i][k]*t[k+1][j] + f[i][k]*f[k+1][j]; 
                } 
            } 
        } 
    } 
    return t[0][n-1];
}
int main()
{
    vector<char> symbols, operators;
    
    symbols.push_back('T');
    symbols.push_back('T');
    symbols.push_back('F');
    symbols.push_back('T');

    operators.push_back('|');
    operators.push_back('&');
    operators.push_back('^');

    cout<<count(symbols,operators)<<endl;
    
}