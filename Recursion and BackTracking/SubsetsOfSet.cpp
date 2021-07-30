// ! Time O(2^n)

#include <bits/stdc++.h>
using namespace std;


void subSetsFind(int pos,vector<int> a,int n,set<vector<int>>& s, vector<int>& curr){
    
    // Base case
    if(pos==n){
        s.insert(curr);
        return;
    }
    
    // Call func with not including 
    subSetsFind(pos+1,a,n,s,curr);
    
    // Including a[pos] into curr and call for pos+1
    curr.push_back(a[pos]);
    subSetsFind(pos+1,a,n,s,curr);
    
    // Backtracking process
    curr.pop_back();
}
vector<vector<int> > AllSubsets(vector<int> A, int n)
{
    sort(A.begin(),A.end()); //To maintain the sorted order
    vector<vector<int>> ans;
    
    set<vector<int>> s;

    vector<int> curr;
    // to find the subsets
    subSetsFind(0,A,n,s,curr);
    
    // Traverse the set and put the element in ans vector
    for(auto i = s.begin(); i != s.end(); i++){
        
        ans.push_back(*i);
    }
    
    return ans;
}


