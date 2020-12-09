#include <bits/stdc++.h>
using namespace std;

void TarjanAlgoSccDFS(vector<int> g[], int start,int& timer,vector<int> disc,vector<int> low,
stack<int> s, vector<bool> inStack, vector<int>& ans){
    
    // Intialize a node with time
    disc[start] = timer;
    low[start] = timer;
    timer++;
    // push into stack and make true in inStack also
    
    s.push(start);
    
    inStack[start] = true;
    
    // Iterate through neighbors
    
    for(auto neigh: g[start]){
        // Not visited
        if(disc[neigh] == -1){
            TarjanAlgoSccDFS(g,neigh,timer,disc,low,s,inStack,ans);
            // When return from neighbor update low timevector<int>& ans
            low[start] = min(low[start], low[neigh]);
            
        }
        // Visited and present in stack BackEdge detected 
        else if(inStack[neigh]){
            low[start] = min(low[start], disc[neigh]);
        }
    } //For end
    
    // Checking whether low[start] == disc[start] means SCC detected
    if(low[start] == disc[start]){
        
        while(s.top() != start){
            ans.push_back(s.top());
            s.pop();
        }
         ans.push_back(s.top());
        
    }
    
}
int main() {

    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        
        vector<int> g[n];
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            
            g[u].push_back(v);
        }
        int start =0;
        int timer = 0;
        stack<int> s;
        vector<bool> inStack(n,false);
        vector<int> disc(n,-1);
        vector<int> low(n,-1);
        vector<int> ans;
        TarjanAlgoSccDFS(g,start,timer,disc,low,s,inStack,ans);
        
        for(int i=0;i<ans.size(); i++){
            cout<<ans[i] <<" ";
        }
        cout<<endl;
    }
    return 0;
}