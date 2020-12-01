#include <bits/stdc++.h>
using namespace std;

vector<int> Spanvalues(vector<int> a,int n){

    vector<int> ans(n);
    stack<pair<int,int>> s;
    
    for(int i=0; i<n; i++){
        
        if(s.empty()){
            ans[i] = -1;
        }    
        else{
            
            while(!s.empty() && (s.top()).first<=a[i]){
                s.pop();
            }
            if(s.empty()){
                ans[i] = -1;
            }else{
               ans[i] =(s.top()).second; 
            }
        }
        s.push(make_pair(a[i], i));
    }
    
    return ans;
    
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    
	    int n;
	    cin>>n;
	    vector<int> a;
	    for(int i=0; i<n; i++){
	        int in ;cin>>in;
	        a.push_back(in);
	    }
	    
	    vector<int> span = Spanvalues(a,n);
	    
	    for(int i=0;i<n; i++){
	        cout<<i-span[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}