// Code snippet 
// ! Time: O(n) and Space: O(1);
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int len = nums.size();
        
//      Extended Moore's Voting Algo
        
        int num1 =-1,num2 = -1,count1 = 0,count2 = 0;
        vector<int> ans;
        for(int num: nums){
//             increment 1st majority element
            if(num == num1)
               count1++;
//             increment 2nd majority element
            else if(num == num2)
                count2++;
                
            
            else if (count1 == 0){
                 count1 =1;
                 num1 =num;
            }
            else if(count2 == 0){
                num2 =num;
                count2 =1;
            }
            else{
                count1--;
                count2--;
            }
        }
        
        count1 =0;
        count2 =0;
        
        for(int num : nums){
            if(num == num1)
                count1++;
            else if(num == num2)
                    count2++;
        }
        
//         If num1 and num2 are Majority element 
        
        if(count1 > len/3)
            ans.push_back(num1);
        
         if(count2 > len/3)
            ans.push_back(num2);
        
        return ans;

        
    }
};