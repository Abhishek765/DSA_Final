#include <bits/stdc++.h>
using namespace std;

void exp_neighbours(int x, int y, int d1, int d2,queue<pair<int,int>>& q, vector<bool> vis[],bool& flag,int N){
    
    // create the direction arr
    int cx[] = {-1,-1,1,1,2,2,-2,-2};
    int cy[] = {2,-2,2,-2,1,-1,1,-1};
    
    // check all directions 
    for(int i=0;i<8;i++){
        
        //if not in range or already visited skip that neighbour
        if(x+cx[i] < 0 || x+cx[i] >= N || y+cy[i] < 0 || y+cy[i] >= N || vis[x+cx[i]][y+cy[i]])
            continue;
            
        // if reach the dest.
        if(x+cx[i] == d1 && y+cy[i] == d2){
            flag = true;
            return;
        }
        
        // else just push it in queue and make it visited
        q.push({x+cx[i],y+cy[i]});
        vis[x+cx[i]][y+cy[i]] = true;
    }//for-end

}
// KnightPos : knight position coordinates
// targetPos : target position coordinated
// N : square matrix size
int minStepToReachTarget(int knightPos[], int targetPos[], int N) {
    int count,steps = 0,i;
    
    int s1 = knightPos[0] -1;
    int s2 = knightPos[1] -1;
    int d1 = targetPos[0] -1;
    int d2 = targetPos[1] -1;
    
   
    // check position of src and dest
    if(s1 == d1 &&  s2 == d2)
        return 0;
    
    // to store the position
    queue<pair<int,int>> q;
    
    // visited arr
    vector<bool> vis[N];

    // initialize the vis
    for(i=0;i<N; i++)
        vis[i].push_back(false);
    
    
    // putting the src into the queue and make it visited
    q.push({s1,s2});
    
    vis[s1][s2] = true;
    
    
    count = q.size();// initial size when src is there
    
    bool flag = false; // to check whether we found the dest or not
    // Do the bfs
    while(count > 0){
        steps++;
        
        // Go through each node
        for(i=0;i<N; i++){
            
            // Take out element from front
            pair<int,int> p = q.front();
            q.pop();
            
            // Explore its neighbours which are in range and not visited
            exp_neighbours(p.first,p.second,d1,d2,q,vis,flag,N);
            
            // check the flag -> if true return the steps
            if(flag){
                return steps;
            }
        }
        
        // Update the count after putting neighbours
        count =q.size();
    }
    
    // if dest. not reachable
    return -1;
    
}