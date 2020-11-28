// ! Time: O(V^3) 
#include <bits/stdc++.h>
using namespace std;

#define INF 1e7
int main() {
    int t; 
    cin>>t;
    while(t--){
        int v;
        cin>>v;
        int dis[v][v];
        for(int i =0; i<v; i++){
            for(int j =0; j<v; j++){
            
                cin>>dis[i][j];
            }
        }
        
       
    // Floyd warshall
    // k intermediate vertices
    for(int k=0; k<v;k++){
        // check if minimization is possible then minimise it
        for(int i =0; i<v; i++){
            for(int j =0; j<v; j++){
            if( (dis[i][k] != INF || dis[k][j] != INF) && dis[i][k] + dis[k][j] <
            dis[i][j])
                dis[i][j] = dis[i][k] + dis[k][j];
            }
        }
    }
    
    
        for(int i =0; i<v; i++){
            for(int j =0; j<v; j++){
                if(dis[i][j] == INF)
                    cout<<"INF ";
                else
                    cout<<dis[i][j]<<" ";
                
            }
            cout<<endl;
        }
        
    }
	return 0;
}