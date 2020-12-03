#include<bits/stdc++.h>
using namespace std;
#define MAX 100

void printCommonElements(vector<vector<int>> mat,int M,int N){

    unordered_map<int,int> m;
    // Traverse the first Row and make element ticket number 100
    for(int i=0;i<N;i++){
        m[mat[0][i]] = 1;
    }

    for(int i=1;i<M;i++){

        for(int j=0;j<N;j++){
            
            // If element is found in next round update the ticket(Row number)
            if(m[mat[i][j]] == i){
                m[mat[i][j]] = i+1;
            }
        }
    }

    for(auto it : m){
        if(it.second == M){
            cout<<it.first<<" ";
        }
    }

}
int main() 
{ 
    int M = 4,N = 5;
    vector<vector<int>> mat = 
    { 
        {1, 2, 1, 4, 8}, 
        {3, 7, 8, 5, 1}, 
        {8, 7, 7, 3, 1}, 
        {8, 1, 2, 7, 9}, 
    }; 
  
    printCommonElements(mat,M,N); 
  
    return 0; 
} 