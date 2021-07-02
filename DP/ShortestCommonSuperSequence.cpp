#include<bits/stdc++.h>
using namespace std;
//! TC: O(n*m)
//! SC: O(n*m)

class Solution
{
    public:
    int LCS(string x, string y, int n, int m){
        
        int dp[n+1][m+1];
        
        // bottom-up approach
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                
                if(i == 0 || j == 0){
                    
                    dp[i][j] = 0;
                    continue;
                }
                
                if(x[i-1] == y[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
                
            }    
        }
        
        return dp[n][m];
        
    }
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //find LCS of x, y
        int len = LCS(X, Y, m, n);
        
        return (m+n) - len;
    }
};