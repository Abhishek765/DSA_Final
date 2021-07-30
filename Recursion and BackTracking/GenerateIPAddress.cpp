// ! Time: O(n^3)
// ! Space : O(n^3)
#include <bits/stdc++.h>
using namespace std;

bool isPartIpValid(string s,int start, int end){
    
    int len =end- start + 1;
    if(len>3) return false;
        
        if(s[start] == '0'){
            if(len == 1) 
               return true;
             else 
               return false;
        }
        
        int value = stoi(s.substr(start,end-start+1));
        if(value >=0 && value <= 255) 
            return true;
            
     return false;
        
}

bool isValidIP(string s, int n, int i, int j, int k){
    
   bool fp= isPartIpValid(s,0,i);
   bool sp= isPartIpValid(s,i+1,j);
    bool tp=isPartIpValid(s,j+1,k);
    bool lp=isPartIpValid(s,k+1,n-1);
    
    return (fp && sp && tp && lp);
}

void add_string(vector<string>& ans, string s, int n, int i, int j, int k){
    string newStr;
    // first part substr(startpos,len)
    
    newStr.append(s.substr(0,i+1));
    newStr.push_back('.');
    
    // second part
    newStr.append(s.substr(i+1,j-i));
    newStr.push_back('.');
    
    // Third part
    newStr.append(s.substr(j+1,k-j));
    newStr.push_back('.');
    
    // Fourth part
    newStr.append(s.substr(k+1,n-1-k));
                
    ans.push_back(newStr);
}
vector<string> genIp(string &s) {
    
    vector<string> ans;
    int n = s.length();
    for(int i=0;i<n-3; i++){
        for(int j=i+1;j<n-2; j++){
            for(int k=j+1;k<n-1; k++){
                    
                if(isValidIP(s,n,i,j,k)){
                    add_string(ans,s,n,i,j,k);
                }
            }
        }
    }
    
    return ans;
}
