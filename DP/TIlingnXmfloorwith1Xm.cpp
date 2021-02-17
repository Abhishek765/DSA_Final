// ! Time: O(n) - for traversing n sized arr and Space: O(n) dp arr

#include <bits/stdc++.h>
using namespace std;


class Solution{
	public:
	   int mod = 1e9 + 7;
		int countWays(int n, int m)
	{
	    int dp[n+1];
	   // Two cases 
	   //when m > n
	   if(m>n){
	       return 1;
	       
	   }
	   // when n >= m
	   else{
	       // for n,m we have to options avialable n-1,m and n-m, m
	       
	       dp[0] = 1;
	       dp[1] = 1;
	       
	       for(int i=2; i<=n; i++){
	           if(i-m >= 0) // i-m is in range
                    dp[i] = (dp[i-1]%mod + dp[i-m]%mod)%mod;
                else
                    dp[i] = dp[i-1]%mod;
	       }
	        
	   }
	   
	   return dp[n]%mod;
	}
};