// ! Time: O(m^v)
// ! Space: O(v)

#include <bits/stdc++.h>
using namespace std;


bool isSafe(int u, int color,bool g[101][101],vector<int>& col,int V){
    
    for(int i=0;i<V; i++){
        // if there is an edge between i and u and their colors are same
        if(g[u][i] && col[i] == color)
            return false;
    }
    
    return true;
    
}
bool mColoring(bool g[101][101], int u, vector<int>& col,int V,int m){
    
    // Base condition when 0.....v-1 are colored
    if(u==V) return true;
    
    for(int i = 0; i<m; i++){
        
        // check if the ith color is safe for u or not
        if(isSafe(u,i,g,col,V)){
            
            // color the vertex u 
            col[u] = i;
            
            // Check for u+1 
            bool flag = mColoring(g, u+1,col,V,m);
            
            // if true means all subnodes are colored 
            if(flag)
                return true;
        }
        // else assign next color
    }
    
    // out of loop means not possible to color u  
    col[u] = -1;
    return false;
    
}
bool graphColoring(bool graph[101][101], int m, int V) {
   
    vector<int> col(V,-1);
    
    bool ans = mColoring(graph,0,col,V,m);

    
    return ans;
}