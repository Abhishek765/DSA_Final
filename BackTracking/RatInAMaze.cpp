// ! Time O((n^2)^4) 
// ! Space O(L*P), L-length of path,P - Number of paths 

#include <bits/stdc++.h>
using namespace std;

#define MAX 5
// issafe for boundary and wall check
bool isSafe(int x,int y, int m[MAX][MAX],int n){
    
    return (x >= 0 && x<n && y >=0 && y<n  && m[x][y] == 1);
}

void ratInMazePaths(int m[MAX][MAX], int n, int row, int col,vector<string>& paths, string& currPath){
    
    // Base case when reached the dest.
    if(row == n-1 && col == n-1){
        paths.push_back(currPath);
        return;
    }
    
    // Possible moves
    int row_change[] = {-1,1,0,0};
    int col_change[] = {0,0,-1,1};
    char dir[] = {'U','D','L','R'};
    
    
    // go through all 4 directions
    for(int i=0; i<4; i++){
        
        // Check whether this path is safe or not
        if(isSafe(row+row_change[i], col + col_change[i],m,n)){
            
            // Make visited its parent
            m[row][col] = 0;
            
            // add direction to currPath
            currPath.push_back(dir[i]);
            
            // Then call recursively from here
            ratInMazePaths(m,n,row+row_change[i], col + col_change[i], paths,currPath);
            
            // If return make the backtracking move
            // Make parent again unvisited
            m[row][col] = 1;
            // and remove this dir
            currPath.pop_back();
        }
    }
    
}
// m is the given matrix and n is the order of matrix
// MAX is the upper limit of N ie 5
vector<string> findPath(int m[MAX][MAX], int n) {
    
    vector<string> paths;
    // Base case when either src or dest. is not reachable i.e 0
    if(m[0][0] == 0 || m[n-1][n-1] == 0)
        return paths;
    
    
    string currPath;
    
    ratInMazePaths(m,n,0,0,paths,currPath);
    sort(paths.begin(), paths.end());
    return paths;
}