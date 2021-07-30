// ! Time O(n*n!)

#include <bits/stdc++.h>
using namespace std;

void permutationsOfStr(int pos, string& currStr,int n,set<string>& s){
    
    // Base case when pos is at last element 
    if(pos == n-1){
        s.insert(currStr);
    }
    
    for(int i=pos; i<n; i++){
        // Swap
        swap(currStr[pos],currStr[i]);
        // call from pos+1 position 
        permutationsOfStr(pos+1,currStr,n,s);
        
        // Backtracking process
        swap(currStr[pos],currStr[i]);
    }
    
}
int main() {
    
    int t; cin>>t;
    
    while(t--){
        
        string currStr;
        cin>>currStr;
        
        int n = currStr.size();
        set<string> s;
        
        permutationsOfStr(0,currStr,n,s);
        
        for(auto str: s){
            cout<<str<<" ";
        }
        cout<<endl;
    }
	return 0;
}