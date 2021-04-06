// ! Time: O(n*sum) and Space is O(n*sum)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool subSetSum(vector<int> arr, int sum,int N){
        
        bool dp[N+1][sum+1];
        // Initialization step
        for(int i=0;i<=N; i++){
            for(int j=0; j<=sum; j++){
                if(i==0)
                    dp[i][j] = false;
                    
                if(j==0)
                    dp[i][j] = true;
    
            }
        }
        
        for(int i=1;i<=N; i++){
            for(int j=1; j<=sum; j++){
               
               if(arr[i-1] <= j){
                //    Two choices whether included or not included
                   dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
               }
               
               else // if element weight is greater than sum
                   dp[i][j] = dp[i-1][j];
            }
        }
        
        
        return dp[N][sum];
        
    }
    bool canPartition(vector<int>& nums) {
        int size = nums.size();
        
//         Variation of Subset sum
        int sum =0;
        
        for(int i: nums)
                sum+= i;
        
        if(sum%2) return false; // for Odd sum partition can't be possible
        
        // else just do the subset sum problem by taking sum as sum/2
        return subSetSum(nums, sum/2,nums.size());
        
    }
};