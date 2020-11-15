// code snippet
#include<bits/stdc++.h>
using namespace std;


bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        
        if(n == 0) return false;
        int m = matrix[0].size();
        
        int down =0,left = m-1;
        
        while(down < n && left >= 0){
            
            if(matrix[down][left] == target) return true;
            
//             move left
            else if (matrix[down][left] > target)
                    left--;
            else
                down++;
        }
        
        return false;
       
    }