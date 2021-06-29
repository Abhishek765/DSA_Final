#include<bits/stdc++.h>
using namespace std;
// ! TC: O(n*sum) SC: O(n*sum)

class Solution{

	public:
	
	 int CoinChangeCount(int coins[], int n, int sum){
        
        int dp[n+1][sum+1];
        
        //Intialization step
        // first row from col=1 should be intialized with INT_MAX -1;
        
        for(int col=1; col<=sum; col++)
            dp[0][col] = INT_MAX-1;

        // 1st col with 0;
        for(int row=0; row<=n; row++)
            dp[row][0] = 0;
            
        // Intialize 2nd row 
        // if col%coins[0] == 0 then dp[1][col] = col/coins[0];
        // else dp[1][col] = INT_MAX - 1;
        for(int col =1; col<=sum; col++){
            
            if(col%coins[0] == 0)
                dp[1][col] = col/coins[0];
            else
                dp[1][col] = INT_MAX - 1;
        }
        
        
        // now start code of Unbounded Knapsack from row=2 and col=1
        for(int row=2; row<=n; row++){
            
            for(int col=1; col<= sum; col++){
                
                //whether included or not
                if(coins[row-1]<= col){
                    dp[row][col] = min(1 + dp[row][col-coins[row-1]],
                                    dp[row-1][col]);
                }
                else
                    dp[row][col] = dp[row-1][col]; // not including case
                
            }
        }
            
        return dp[n][sum];
    }
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    int minCoins = CoinChangeCount(coins, M, V);
	    return  minCoins != INT_MAX-1 ? minCoins : -1;
	} 
	  
};