// ! Code Function snippet
#include<bits/stdc++.h>
using namespace std;
#define MAX 100


int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    // Min Heap - priority_queue<int , vector<int>, greater<int>> pq;
    // priority_queue<  {element, {rowindex, colindex}  }    >  
  priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
  
//Traverse first row and put element and row and col indexes
    for(int i=0;i<n;i++){
        pq.push({mat[0][i], {0,i}});
    }
    
    while(!pq.empty())
      {
        //   Decrement k
          k--;
        //   Take out min element 
        pair<int,pair<int,int>> temp = pq.top();
        pq.pop();
        
        // If found kth smallest
        if(k==0){
            return temp.first;
        }
        
        int newRowIndex = temp.second.first;
        int newColIndex = temp.second.second;
        
        if(newRowIndex < n-1){
             pq.push({mat[newRowIndex + 1][newColIndex], {newRowIndex + 1,newColIndex}});
        }
          
      }
  
  return -1;
  
}