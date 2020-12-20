// code snippet
#include<bits/stdc++.h>
using namespace std;

int spanningTree(int V, int E, vector<vector<int>> &g) {
    // Initialization
    vector<bool> vis(V,false);
    vector<int> dis(V,INT_MAX);
    vector<int> parent(V);
    int src = 0;
    
    dis[src] = 0;
    parent[src] = -1;
    
    // set with pair of <weight, vertex>
    set<pair<int,int>> s;
    
    
    for(int i=0; i<V; i++){
        if(i == src){
            // if src then src weight is 0
            s.insert({0, src});
        }
        else{
        //rest of the vertices
        s.insert({INT_MAX,i});
        }
            
    }
    
    while(!s.empty()){
         // take out first element 
        auto itrPair = *(s.begin());
        s.erase(s.begin());
        
        int u = itrPair.second;
        // Make it visited
        vis[u] = true;
        
        // check for its neighbors
        for(int v =0; v<V; v++){
            // if node is not visited then only relax it
            if(!vis[v]){
                // checking whether edge is present and
                // edge weight btw u and v is minimum or not
                if(g[u][v] &&  g[u][v] < dis[v]){
                    
                    auto itr = s.find({dis[v], v});
                    
                    // check if this node present or not
                    
                    // If present
                    if(itr != s.end()){
                        // delete it from set
                        s.erase(itr);
                        
                        // Updating the dis with new weight
                        dis[v] = g[u][v];
                        
                        // add to the set also
                        s.insert({dis[v], v});
                    }
                }
            }
        }
    }
    
    int sum = 0;
    for(auto i: dis){
        sum+=i;
    }
    
    return sum;
}