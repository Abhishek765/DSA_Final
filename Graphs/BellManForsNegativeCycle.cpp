// !Time : O(VE)
#include <bits/stdc++.h>
using namespace std;
int checkForCycle(vector<vector<int>> g, vector<pair<int,int>> eL, int src,int V){
    
    vector<int> dis(V+2,INT_MAX);
    
    dis[src] = 0;
    int e = eL.size();
    // Relaxation
    
    for(int i=0; i<V-1; i++){
        // Traversing the edgeList
        for(int j=0; j<e; j++){
            
            int u = eL[j].first;
            int v = eL[j].second;
            
            if(dis[u] != INT_MAX && dis[u] + g[u][v] < dis[v])
                dis[v] = dis[u] + g[u][v];
        }
    }
    int cycle = false;
    // after v-1 time relaxation one more time do the same
    for(int j=0; j<e; j++){
        
         int u = eL[j].first;
         int v = eL[j].second;
         
         if(dis[u] != INT_MAX && dis[u] + g[u][v] < dis[v]){
                dis[v] = dis[u] + g[u][v];
                cycle = true;
             
         }
    }
    
    return cycle == true;
    
}
int main() {

    int t; 
    cin>>t;
    while(t--){
        int V,e;
        cin>>V>>e;
        vector<vector<int>> g(V);
        vector<pair<int,int>> edgeList; 
        for(int i=0; i<e; i++){
            int u,v,w;  
            cin>>u>>v>>w;
            g[u].push_back(w);

            edgeList.push_back(make_pair(u,v));
        }
        int src = 0; 
        // cout<<edgeList.size()<<endl;
        cout<<checkForCycle(g,edgeList,src,V)<<endl;
    }
	return 0;
}