#include <bits/stdc++.h>
using namespace std;
void floodfill(int x, int y, int old_color,int new_color,vector<vector<int>>& M,
int row,int col){
    
    // Base condition
    // if coordinates out of range
    if(x<0 || x>=row || y<0 || y>=col)
        return;
    // if color at [x,y] is not matched
    if(M[x][y] != old_color)
        return;
    
    // change the current old_color to new_color
    M[x][y] = new_color;
    
    // call its all four directions
    floodfill(x-1,y,old_color,new_color,M,row,col);
    floodfill(x+1,y,old_color,new_color,M,row,col);
    floodfill(x,y-1,old_color,new_color,M,row,col);
    floodfill(x,y+1,old_color,new_color,M,row,col);
}
int main() {
	
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    vector<vector<int>> M;
	    for(int i=0;i<n;i++){
	        vector<int> temp;
	        for(int j=0;j<m;j++){
	            int in; cin>>in;
	            temp.push_back(in);
	        }
	            M.push_back(temp);
	    }
	    
	    
	    int x,y,K;
	    cin>>x>>y>>K;
	    int old_color = M[x][y];
	    floodfill(x,y,old_color,K,M,n,m);
	    
	    
	     for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            cout<<M[i][j]<<" ";
	        }
	    }
	    
	    cout<<endl;
	}
	return 0;
}