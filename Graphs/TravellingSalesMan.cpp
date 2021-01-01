#include <bits/stdc++.h>
using namespace std;


void travellingSalesProb(vector<vector<int>> g,vector<bool>& vis, int u,int count,
int& min_cost,int curr_cost, int n){
    
    // make the curr node visited and increase the count
    vis[u] = true;
    count++;
    
    // Base condition 
    if(count == n){
        
        // check whether curr node is 0 or not and update the min_cost
        if(g[u][0] && curr_cost + g[u][0] < min_cost){
            min_cost = curr_cost + g[u][0];
        }
        // make the node unvisited and return from function call
        vis[u] = false;
        return;
    }
    
    // traverse the neighbours
    for(int v=0;v<n;v++){
        
        if(g[u][v] && !vis[v]){
            travellingSalesProb(g,vis,v,count,min_cost,curr_cost + g[u][v],n);
        }
        
    }
    
    vis[u] = false;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    
	    int n;
	    cin>>n;
	    vector<vector<int>> g;
	    
	    for(int i=0;i<n;i++){
	        vector<int> temp;
	        
	        for(int j=0;j<n;j++){
	            int in; cin>>in;
	            temp.push_back(in);
	        }
	        g.push_back(temp);
	    }
	    
	   // for(int i=0;i<n;i++){
	        
	   //     for(int j=0;j<n;j++){
	   //         cout<<g[i][j]<<" ";
	   //     }
	   //     cout<<endl;
	   // }
	    
	    vector<bool> vis(n,false);
	   // starting from 0
	    int start = 0;
	    int count=0;
	    int min_cost = INT_MAX;
	    int curr_cost = 0;
	    
	    travellingSalesProb(g,vis,start,count,min_cost,curr_cost,n);
	    
	    cout<<min_cost<<endl;
	    
	    
	}
	return 0;
}