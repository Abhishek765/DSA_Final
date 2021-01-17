// ! Time: O(9^(n^2))
// ! Space: O(n*n)
#include <bits/stdc++.h>
using namespace std;
#define N 9

bool checkRowConst(int row, int col,int k, int grid[N][N]){
    
    for(int j=0;j<9;j++){
        
        if(grid[row][j] == k) return false;
    }
    return true;
}
bool checkColConst(int row, int col,int k, int grid[N][N]){
    
    for(int i=0;i<9;i++){
        
        if(grid[i][col] == k) return false;
    }
    return true;
}

bool checkSubMatConst(int row, int col,int k, int grid[N][N]){
    int rs, re, cs, ce;
    
    // find the subMatrix first
    for(int i=0; i<9; i+= 3){
        
        if(row >= i && row < i+3){
            rs = i;
            re = i+3;
        }
        
        if(col >= i && col < i+3){
            cs = i;
            ce = i+3;
        }
    }
    
    // traverse through the subMatrix
    for(int i=rs; i<re; i++)
        for(int j=cs; j<ce; j++)
            if(grid[i][j] == k) // Means we found a element in the subMat ==> fail to fill
                return false;
    
    
    return true;
}


bool isValid(int row,int col, int k,int grid[N][N]){
    
    return (checkRowConst(row, col, k,grid) && 
    checkColConst(row, col, k,grid) && checkSubMatConst(row, col, k,grid));
    
}
bool sudoku(int row, int col, int grid[N][N]){
    
    // if my row index crossed the matrix boundary 
    if(row == N) return true; //means we got the solution for that particular
    
    
    // filled condition ->this particular cell is already move to next cell 
    if(grid[row][col] != 0){
        
        // move to next row condition
        if(col == 8){
                return sudoku(row + 1, 0, grid);
        }
        // means just move to next column
        else{
                return sudoku(row, col+1, grid);
        }
            
    }
    
//   else means cell is not filled
    // fill it with possible K values
    for(int K=1; K<=9; K++){
        
        // checking the constraints
        if(isValid(row,col,K,grid)){
            // if current K value can be filled in that cell -> fill it
            grid[row][col] = K;
            // After filling move to next cell
            if(col == 8){
                if(sudoku(row + 1, 0, grid))
                    return true; // means we got the solution for sub part
            }
            // means just move to next column
            else{
                if(sudoku(row, col+1, grid))
                    return true;
            }
            // Backtracking process -> at this point means we can't fill current cell with this K value
            // So remove it and move to next K value
            grid[row][col] = 0;
            
        }
        
    }
    
    // Solution is not possible for current grid
    return false;
    
}

bool SolveSudoku(int grid[N][N])  
{ 
    // calling the util function which handles if solution is possible or not
    return sudoku(0,0,grid); 
}

void printGrid (int grid[N][N]) 
{
    int i,j;
    for(i=0;i<9; i++){
        for(j=0;j<9; j++){
            
            cout<<grid[i][j]<<" ";
        }
    }
}