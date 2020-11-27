// code snippet
#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
    int firstIndex(vector<int> a, int start, int end){
       
        
        while(start <= end){
            
            int mid = start + (end - start)/2;
            
            if((mid == 0 || a[mid-1] == 0)&& a[mid] == 1)
                return mid;
            else if (a[mid] == 0){
                return firstIndex(a,mid + 1,end);
            }
            else
                return firstIndex(a,start, mid - 1);
        }
        return -1;
    }
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int maxRowindex = 0;
	   
	    int j = firstIndex(arr[0], 0, m - 1);
        if(j == -1){
            j=m - 1;
            maxRowindex = -1;
        }
         
         
         for(int i=0; i<n; i++){
                // Moving left side of a row and checking for 1
                while(j>=0 && arr[i][j] == 1){
                 j--;
                 maxRowindex = i;
             }
            
         }
         
         return maxRowindex;
	}

};

