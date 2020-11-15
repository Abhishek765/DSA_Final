// code snippet
#include<bits/stdc++.h>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c) 
    {
        vector<int> ans;
        
        int i, startRow=0, startCol = 0;
        
        while(startRow < r && startCol < c){
            
            for(i=startCol; i<c; i++){
                // cout<<matrix[startRow][i];
                ans.push_back(matrix[startRow][i]);
            }
            startRow++;
            
            for(i=startRow; i<r; i++){
                // cout<<matrix[i][c-1];
                ans.push_back(matrix[i][c-1]);
                
            }
            c--;
            
            if(startRow < r){
                
                for(i=c-1; i>=startCol; i--){
                    // cout<<matrix[r-1][i];
                    ans.push_back(matrix[r-1][i]);
                }
                r--;
            }
            
            if(startCol < c){
                for(i=r-1; i>=startRow; i--){
                    // cout<<matrix[i][startCol];
                    ans.push_back(matrix[i][startCol]);
                }
                startCol++;
            }
            
        }
        
        return ans;
    }
