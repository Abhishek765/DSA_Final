// ! Time: O(n) and Space is O(1)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        
        if(nums[0] == 0) return false;
        
        int dest = nums.size() - 1;
//         checking from Backwards from 2nd last index if I can reach dest from current i -> if yes then we'll update our dest to current i and check again for this dest
        for(int i=nums.size() - 2;i>=0 ; i--){
            
            int sum = i + nums[i];
             if(sum >= dest){
                 dest = i;
             }
        }
        
        return dest<=0;
    }
};