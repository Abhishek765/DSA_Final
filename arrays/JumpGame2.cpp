// ! Time: O(n) and Space is O(1)

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();
//         Base case when size < 2
        if(n < 2) return 0;
        
//         Initially we can reach max to nums[0]
        int maxReachableIndex = nums[0]; 
        // intially my limit is 0 + nums[0]; 
        int limit = nums[0];
        
//         Make one jump from 0 
        int minJumps = 1;
        
//         Check from 1 to n-1 
        for(int i=1; i<n; i++){
            
//             If we reach the current limit i.e i + nums[i], so we need to change out new limit and take next jump
            if(i > limit){
                minJumps++;
                limit = maxReachableIndex;
            }
//             if my i is not greater than current limit than we need to update our maxReachableIndex to i+nums[i] i.e from i we can reach to max of i+nums[i]
            maxReachableIndex = max(maxReachableIndex, i + nums[i]);         
                       
        }
        
        return minJumps;
            
    }
};




