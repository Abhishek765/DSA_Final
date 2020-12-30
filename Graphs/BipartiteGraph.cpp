#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

bool dfs(int g[][MAX],vector<int>& col,int start,int V,int cr){
    
    // if not visited check the color of start and node
    if(col[start] == -1)
        return col[start] == cr;
        
    // initialize the color of start
    col[start] = cr;
    
    // traverse the neighbours
    for(int i=0;i<V; i++){
       
             // if not visited check if i neighbour of start by checking edge btw them
            if(col[i] == -1){
                // apply dfs with change the color to 1-cr
                // if false returned means no bipartite in subgraph
                if(g[start][i] && !dfs(g,col,i,V,1-cr))
                    return false;
            }
            
    }
    // if no false returned from loop means bipartite exists 
    return true;
}
/*The function takes an adjacency matrix representation of the graph (g)
and an integer(v) denoting the no of vertices as its arguments.
You are required to complete below method */
bool isBipartite(int G[][MAX],int V)
{
    vector<int> col(V,-1);


    // if graph is diconnected check for each node
    for(int i=0;i<V; i++){
        
        if(col[i] == -1){
            // No bipartite in subgraph
            if(!dfs(G,col,i,V,0)){
                return false;
            }
        }        
    }
    return true;
}