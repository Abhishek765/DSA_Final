#include<bits/stdc++.h>
using namespace std;

void av()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}


bool backTrackingDFS(int g[][16],int start, vector<bool>& vis,int& count,int V){
    
    // make start visited and increase the count
    vis[start] = true;
    count++;
    
    // check for count is equal to no of vertices or not
    if(count == V)
        return true;
       
    // else traverse the neighbours 
    for(auto node : g[start]){
        
        if(!vis[node]){
            
            bool flag = backTrackingDFS(g,node,vis,count,V);
            
            if(flag)
                return true;
        }
    }
    
    // else-> means current node not covering the entire the nodes(vertices)
    // therefore, decrese the count and make it unvisited and return false from here
    vis[start] = false;
    count--;
    
    return false;
}
int main() {
	av();
	int t; cin>>t;
	while(t--){
	    
	     int V,E;
        cin>>V>>E;
    
        int adj[16][16];
        
        for(int i=0;i<16;i++)
            for(int j=0;j<16;j++)
               adj[i][j] = 0;
        
        
        int u,v;
        while(E--){
            cin>>u>>v;
            adj[u][v] = 1;
            adj[v][u] = 1;
        }

	    
	    int count=0;
	    vector<bool> vis(V,false);
	    int f = 0;
	    for(int i=0;i<V;i++){
	        
	       // each time for new i Make count = 0 and vis all to false
	       count=0;
	       fill(vis.begin(), vis.end(),false);
	       
	       //Apply the dfs with backtracking to check the hamiltonian path
	       
	        if(backTrackingDFS(adj,i, vis, count,V)){
	            f=1;
	            break;
	        }
	    }
	   
	   if(f)
	        cout<<"1\n";
	   else 
	        cout<<"0\n";
	    
	}
	
	return 0;
}