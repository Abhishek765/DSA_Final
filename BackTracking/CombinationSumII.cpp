
//** Distinct elements case **//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void combinationSumUtil(int pos, int n,int sum,int target,vector<int>& currCombination, set<vector<int>>& res,vector<int> candidates){
        
//         Base condition
            if(sum ==target){
                res.insert(currCombination);
                return;
            }
        
            if(pos == n || sum > target){
                return;
            }
            
        
//            traverse from pos to last element 
        for(int i=pos; i<candidates.size(); i++){
            
//             Ignore duplicate combination
            if(i&&candidates[i]==candidates[i-1]&&i>pos) continue;
            
            if(candidates[i] + sum <= target){
             sum += candidates[i];
             currCombination.push_back(candidates[i]);
             combinationSumUtil(i+1, n,sum, target,currCombination,res,candidates);
//              Backtracking process
             sum -= candidates[i];
             currCombination.pop_back();
            }
        }
                            
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
          sort(candidates.begin(),candidates.end());
        
        vector<vector<int>> res;
        set<vector<int>> tempres;

        vector<int> currCombination;
        int sum = 0;
        int pos=0;
        
        int n = candidates.size();
        
        combinationSumUtil(pos,n,sum,target,currCombination, tempres, candidates);
            
         for(auto vec: tempres){
             res.push_back(vec);
         }
        return res;
    }
};

