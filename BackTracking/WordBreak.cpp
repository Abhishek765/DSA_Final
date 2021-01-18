// ! Time: O(2^n)
#include<bits/stdc++.h>
using namespace std;

// A : given string to search
// B : vector of available strings

bool isStrWordBreak(int i,int j, int n, string A, vector<string>& dict){
    
    // Base condition
    if(j==n){ // if j crossed
        if(i==n)
            return true;
            
        return false;
    }
    
    // check if str from i to j is found or not in dict
    if(find(dict.begin(), dict.end(), A.substr(i,j-i+1)) == dict.end()){
        // if not found
        // increment j and call recursively
        return isStrWordBreak(i,j+1, n,A,dict);
    }
    else{
        // found do the split and no split steps
        
        // No split
        if(isStrWordBreak(i,j+1, n,A,dict)) return true;
        // else Split -> both i and j will shift to j+1
        return isStrWordBreak(j+1,j+1, n,A,dict);
        
    }
    
}

int wordBreak(string A, vector<string> &B) {
    return isStrWordBreak(0,0,A.size(), A, B);
}