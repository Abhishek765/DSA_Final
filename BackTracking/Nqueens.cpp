// ! Time: O(n^n)
// ! Space: O(n^2)
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
bool isSafe(int row, int col, int n, vector<int> &queenArrangement){
    int i,j,temp;

    //Checks if it is row safe
    for(int r:queenArrangement){
        if(r == row) return false;
    }

    //Check if it upper diagonal safe
    temp = row-1;
    for(i=queenArrangement.size()-1;i>=0;i--){
        if(temp <= 0) break;
        if(temp == queenArrangement[i]) return false;
        temp--;
    }

    //Check if it is lower diagonal safe
    temp = row+1;
    for(i=queenArrangement.size()-1;i>=0;i--){
        if(temp > n) break;
        if(temp == queenArrangement[i]) return false;
        temp++;
    }

    return true;
}
    void nQueens(int col, int n,vector<int>& currArrangements,vector<vector<int>>& possibleCombinations){
        
        // Base condition found one arrangement
        if(col > n){
            possibleCombinations.push_back(currArrangements);
            return;
        }
        
        // for the given col check in every row
        for(int row = 1; row<=n; row++){
            
            // If particular row and col is safe
            if(isSafe(row,col,n,currArrangements)){
                currArrangements.push_back(row);
                nQueens(col+1,n,currArrangements,possibleCombinations);
                currArrangements.pop_back();
            }
        }
        
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> possibleCombinations;
        
        vector<int> currArrangements;
        
        nQueens(1,n,currArrangements, possibleCombinations);
        
        return possibleCombinations;
    }
};