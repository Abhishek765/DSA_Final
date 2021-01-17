// ! The largest number of elements in a combination sum would be [min, min, min ...], and to get the upper bound, we can say that for each element in the max length combination array, we can pick from any of the elements we are given.
// ! Therefore, the complexity should be: len(candidates)^ (target/min(candidates))

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
 //**    With excluding Method **//
    void combinationSumUtil(int pos, int n,int sum,int target,vector<int>& currCombination, vector<vector<int>>& res,vector<int> candidates){
        
//         Base conditions
            if(sum == target){
                res.push_back(currCombination);
                return;
            }
//             reached all elements or sum exceeds target    
            if(pos == n || sum > target)
                return;
        
            // include curr pos element
                sum += candidates[pos];
                currCombination.push_back(candidates[pos]);
            
                combinationSumUtil(pos, n,sum,target,currCombination,res,candidates);
        
//                 Backtracking process
                sum -= candidates[pos];
                currCombination.pop_back();
        
//                 Exclude the curr pos element move to pos+1
            
                combinationSumUtil(pos+1, n,sum,target,currCombination,res,candidates);

    }

 //**    WithOut excluding Method **//

//     void combinationSumUtil(int pos, int n,int sum,int target,vector<int>& currCombination, vector<vector<int>>& res,vector<int> candidates){
//         if(sum==target)
//             {
//                 res.push_back(currCombination);
//                 return;
//             }
        
//             for(int i=pos;i<candidates.size();i++)
//             {
//                 if(candidates[i]+sum<=target)
//                 {
//                     currCombination.push_back(candidates[i]);
//                     sum+=candidates[i];
//                     combinationSumUtil(i,n,sum,target,currCombination,res,candidates);
//                     sum-=candidates[i];
//                     currCombination.pop_back();
//                 }
//             }
//             return;
//     }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // ! Below two lines for gfg to get the unique solution
        //  sort(candidates.begin(),candidates.end());
        //     candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
        
        vector<vector<int>> res;
        vector<int> currCombination;
        int sum = 0;
        int pos=0;
        
        int n = candidates.size();
        
        combinationSumUtil(pos,n,sum,target,currCombination, res, candidates);
            
        return res;
    }
};