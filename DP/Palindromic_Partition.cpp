#include <bits/stdc++.h>
using namespace std;
//! TC: O(n^2)
//! SC: O(n^2)



class Solution{
public:

    int dp[501][501];
    bool isPalindrome(string& s, int start, int end){
        
        while(start < end){
            
            if(s[start] != s[end]) {
                return false;
            }
                
            start++;
            end--;
        }
        
        return true;
    }
    int solve(string& s, int i, int j){
        
        // Base condition if string is empty or single character -> already a palindrome 
        // OR if string between i to j is palindrome then return 0
        if(i >= j || isPalindrome(s, i, j))
            return 0;

        // if answer already present in dp
        if(dp[i][j] != -1) 
            return dp[i][j];
        
        int res = INT_MAX;
        
        // for storing left and right part answers
        int left, right;
        
        // Deciding the k - loop 
        for(int k=i; k<j; k++){
            
            // if i to k is already solved
            if(dp[i][k] != -1){
                left = dp[i][k];
            }
            else{
                // else we need to make the recursive call
                left = solve(s, i, k);
                dp[i][k] = left;
                
            }
            
            // if k+1 to j is already solved
            if(dp[k+1][j] != -1){
                right = dp[k+1][j];
            }
            else{
                // else we need to make the recursive call
                right = solve(s, k+1, j);
                dp[k+1][j] = right;
                
            }
            
            int tempAns = 1 + left + right;
            
            res = min(res, tempAns);
        }
        
        return dp[i][j] = res;
            

    }
    int palindromicPartition(string str)
    {
        int n = str.length();
        memset(dp, -1, sizeof(dp));
        return solve(str, 0, n-1);
    }
};