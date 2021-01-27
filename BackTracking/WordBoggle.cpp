// ! Time : O(N*W + R*C^2) -: N is dict size, W is word size, R is row, C is column
// ! Space: O(R*C) -> for visited array 
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isWordBoggle(int start, int len, string word,int m, int n, int row, int col, 
   vector<vector<char>>& board, vector<bool> vis[]){
       
    //*   Base conditions *//
    // 1. if start cross the len of word means word found
    if(start == len){
        return true;
    }
    
    // 2.checking the range of index
    if((row < 0 || row >= m) || (col < 0 || col >= n)){
        return false;
    }
    
    // 3. if adjacent cell is already visited or character doesn't match
    if(vis[row][col] || word[start] != board[row][col]){
        return false;
    }
    
    // making current cell visited
    vis[row][col] = true;
    
    // dfs in adjacent directions (8 directions except 0,0)
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
                        
            if(i==0 && j==0)
                continue;
            //  call adjacent recursively and if word found return true
            if(isWordBoggle(start+1, len, word, m, n, row + i, col + j, board, vis))
                return true;
                
        }        
    }
    
    // if this word not found try another
    // backtracking step
    vis[row][col] = false;
    
    return false;
       
   }
    
    bool searchWord(string word, vector<vector<char> >& board, int m, int n){
        
        // Visited add list (2d)
        vector<bool> vis[m];
        
        // intialize visited to false 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vis[i].push_back(false);
            }
        }
        
        
        // go through the board 
        for(int i=0;i<m;i++){
            for(int j=0; j<n; j++){
                // call isWordBoggle if first character is found to check for whole word using dfs
                if(word[0] == board[i][j]){
                    
                    // if word found
                    if(isWordBoggle(0,word.length(), word, m, n, i, j,board,vis))
                        return true;
                }
            }
        }
      
    //   word not found 
    return false;
    }

	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    
	    
	int m = board.size();
    int n = board[0].size();
    
    vector<string> res;
    int i,j,k;
    
    for(i=0;i<dictionary.size();i++){
        // If particular word is found in board add it to result
        if(searchWord(dictionary[i],board,m,n)){
            res.push_back(dictionary[i]);
        }
    }
    return res;
	    
	}
};