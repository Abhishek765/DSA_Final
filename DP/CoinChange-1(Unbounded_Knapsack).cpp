#include<bits/stdc++.h>
using namespace std;
// ! TC: O(n*sum) SC: O(n*sum)
class Solution
{
  public:
    long long int CoinChangeCount(int s[], int n, int sum){
        
        long long int dp[n+1][sum+1];
        
        for(int col=0; col<=sum; col++)
            dp[0][col] =0;
            
        for(int row=0; row<=n; row++)
            dp[row][0] =1;
            
        for(int i=1; i<=n; i++){
            
            for(int j=1; j<= sum; j++){
                
                //whether included or not
                if(s[i-1]<= j){
                    dp[i][j] = dp[i-1][j] + dp[i][j-s[i-1]];
                }
                else
                    dp[i][j] = dp[i-1][j]; // not including case
                
            }
        }
            
        return dp[n][sum];
    }
    long long int count( int S[], int m, int n )
    {
        return CoinChangeCount(S, m, n);
        
    }
};