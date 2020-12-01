
/** 
* !Time Complexity : O(n)
* ! Expected Auxilliary Space : O(n)
**/
#include <bits/stdc++.h>
using namespace std;

vector <long long> nextLargerElement(long long arr[], int n){

    vector<long long> ans(n);
    
    stack<long long> s;
    
    for(int i=n-1; i>=0; i--){
        if(s.empty()){
            ans[i] = -1;
        }
        else{
           
            while(!s.empty() && s.top()<=arr[i]){
                s.pop();
            }
            if(!s.empty()){
                // ans.push_back(s.top());
                ans[i] = s.top();
            }else{
                // ans.push_back(-1);
                ans[i] = -1;
            }
            
        }
        s.push(arr[i]);
        
        
    }
    
    // reverse(ans.begin(), ans.end());
    
    return ans;
}