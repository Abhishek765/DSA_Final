// code snippet
#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int> g[],int n, bool vis[], int start, int parent){
 //  make current node visited
    vis[start] = true;
    // traverse through its neighbors
    for(auto neig: g[start]){
        
        if(!vis[neig]){
            if(dfs(g,n,vis, neig, start))
                return true;
        }
        else{
                if(neig != parent){
                    // cycle detected
                    return true;
                }
            }
    }
    
    return false;
}
bool isCyclic(vector<int> g[], int V)
{
    bool vis[V];
     for(int i=0; i<V; i++){
     
         vis[i] = false;
     }     
         
    for(int i=0; i<V; i++){
        
        if(!vis[i]){
            if(dfs(g,V,vis,i,-1)){
                return true;
            }
        }
    }
    return false;

}