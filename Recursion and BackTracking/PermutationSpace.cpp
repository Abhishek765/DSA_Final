// ! Time O(2^n) 
// ! Space O(2^n) 

#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    void permutationsSpace(string& currStr, set<string>& s, int start, int len){
        
        // Base case
        if(start == len-1){
            s.insert(currStr);
            return;
        }
        
        // Call left->without space
        permutationsSpace(currStr,s,start+1,len);
        
        // Add space 
        currStr.insert(start + 1, " ");
        // Right call -> With space
        permutationsSpace(currStr,s,start + 2, len+1);
        
        // Backtracking process remove the space
        currStr.erase(start + 1, 1);
    
    }
    vector<string> permutation(string S){
        
        set<string> strSet;
        permutationsSpace(S,strSet,0,S.size());
        
        vector<string> ans(strSet.begin(), strSet.end());
        
        return ans;
    }
};