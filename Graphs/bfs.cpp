#include<bits/stdc++.h>
using namespace std;

vector <int> bfs(vector<int> g[], int n) {

    vector<int> ans;
    
    queue<int> q;
    
    bool vis[n];
    for(int i=0; i<n; i++){
        vis[i] = false;
    }
    //putting source 
    q.push(0);
    // cout<<"Front element: "<<q.front();
    vis[0] = true;
    
    while(!q.empty()){
        //taking front
        int temp = q.front();
        q.pop();
        ans.push_back(temp);
        
        // checking neighbors
        for(int i=0; i<g[temp].size(); i++){
            if(vis[g[temp][i]] == false ){
                q.push(g[temp][i]);
                vis[g[temp][i]] = true;
            }
        }
    }
    
    return ans;
    
}

int main(){
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector <int> res = bfs(adj, N);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout << endl;
    }
}