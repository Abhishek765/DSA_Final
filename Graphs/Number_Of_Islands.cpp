// code snippet
#include<bits/stdc++.h>
using namespace std;

bool isValid(int X, int Y, int N, int M,vector<vector<bool>>& vis){
    
    if( (X>=0 && X<=N-1) && (Y>=0 && Y<=M-1) && vis[X][Y]  == false)
        return true;
    
    return false;
}
void Dfs(vector<int> A[], int N, int M, int x, int y, vector<vector<bool>>& vis){
    
    // make curr cell true i.e visited
    vis[x][y] = true;
    
    // Checking for neighbors i.e corresponding 8 cells 
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            
            // if curr cell 0,0
            if(i == j && i==0)
                continue;
            
            // Checking whether particular cell is in boundary and not visited
            if(isValid(x+i,y+j, N,M,vis)){
                // true means valid apply dfs
                Dfs(A,N,M,x+i,y+j, vis);
                
            }
        }
    }
    
}
//! Main function to calulate Islands
int findIslands(vector<int> A[], int N, int M) {

    vector<vector<bool>> vis;
    
    // Intialization Visited array to true
    for(int i=0;i<N;i++){
        vector<bool> temp;
        for(int j=0;j<M;j++){
           temp.push_back(true);
        }
        vis.push_back(temp);
    }
    
    // set to false wherever 1 encounters
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(A[i][j] == 1)
                vis[i][j] = false;
            
    int count = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            
            // if visited is false then apply dfs and count the dfs
            if(!vis[i][j]){
                Dfs(A,N,M,i,j,vis);
                count++;
            }
        }
     
    }
   
    return count;
}