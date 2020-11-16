// code snippet
#include<bits/stdc++.h>
using namespace std;


int median(vector<vector<int>> &matrix, int r, int c){
        // Using binary search Upper_bound concept that at median n/2 elements are 
        // less than median 
        int min = INT_MAX, max= INT_MIN;
        // takes O(r) time
        for(int i=0; i<r; i++){
            
            if(matrix[i][0] < min)
                min = matrix[i][0];
            
            if(matrix[i][c-1] > max)
                max = matrix[i][c-1];
        }
        
        
        int currMedianPos = (r*c+1)/2;
        // takes O(log(c)) time
        while(min < max){
            int mid = min + (max - min)/2;
            int count =0;
            
            for(int i=0;i<r; i++){
                // finding Upper bound of mid in each row
                count+= upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                
            }
            
            if(count < currMedianPos)
                min = mid + 1;
                
            else 
                max = mid;
        }
        
        return min;
    }