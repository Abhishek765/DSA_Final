#include <bits/stdc++.h>
using namespace std;

void av()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

void dfs(vector<int> g[],int start,vector<bool>& vis,stack<int>& s, int V){
    
    vis[start] = true;
    
    // neighbours2
    for(auto node: g[start]){
        
        if(!vis[node])
            dfs(g,node,vis,s,V);
    }
    
    s.push(start);
}
string topoSort(vector<int> g[],int V){
    
    stack<int> s;
    string ans;
    vector<bool> vis(V,false);
    

    for(int i=0;i<V;i++){
        
        if(!vis[i])
            dfs(g,i,vis,s,V);
    }
    
    while(!s.empty()){
        ans.push_back((char)(s.top() + 'a'));
        s.pop();
    }
    
    return ans;
    
}
string findOrder(string dict[], int N, int K) {
    // Steps
    // 1 - find the first point of difference between two adjacent pairs in arr 
    // and form the graph
    // 2- Apply the topological sort and store the order in string 
    
    // make the graph for K no of alphabets
    vector<int> g[K];
    
    // traverse through the arr
    for(int i=0; i<N-1; i++){
        
        // finding the minlenght between two adjacent
        int minLen = min(dict[i].length(), dict[i+1].length());
        // cout<<"minLen: "<<minLen<<endl;
        // compare two adjacent strings till minLen and find the first point of difference 
        for(int j=0;j<minLen; j++){
            if(dict[i][j] != dict[i+1][j]){
                        // cout<<"first: "<<dict[i][j] <<" Second: "<<dict[i+1][j]<<endl;

                // if found the first different character store it in graph and break the loop
                g[dict[i][j] - 'a'].push_back(dict[i+1][j] - 'a');
                break;
            }
            
        }
            
    }
    
    string ans;
   
    // after we have our graph just topological sort
    ans = topoSort(g,K);
    // cout<<"ans: "<<ans<<endl;
    return ans;
}

int main() {

    av();

    string words[] = {"baa", "abcd", "abca","cab" ,"cad"};
    string ans = findOrder(words,5,4);

    cout<<ans<<endl;

    return 0;
}