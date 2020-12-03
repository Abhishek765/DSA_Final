// code snippet
#include<bits/stdc++.h>
using namespace std;
#define MAX 100

void PerformNSR(int a[], int n, vector<int>& right){
    
    stack<pair<int, int>> s;
    
    for(int i=n-1; i>=0; i--){
        if(s.empty()){
            right[i] = n;
        }
        else{
            
            while(!s.empty() && s.top().first >= a[i])
                s.pop();
            
            if(!s.empty()){
                right[i] = s.top().second;
            }else{
                right[i] = n;
            }
            
        }
        
        s.push({a[i], i});
    }
}
void PerformNSL(int a[], int n, vector<int>& left){
    
    stack<pair<int, int>> s;
    
    for(int i=0; i<n; i++){
        if(s.empty()){
            left[i] = -1;
        }
        else{
            
            while(!s.empty() && s.top().first >= a[i])
                s.pop();
            
            if(!s.empty()){
                left[i] = s.top().second;
            }else{
                left[i] = -1;
            }
            
        }
        
        s.push({a[i], i});
    }
}
long MaH(int arr[], int n){
    // NSR
    vector<int> right(n);
    // NSL
    vector<int> left(n);
    
    PerformNSR(arr,n,right);
    
    PerformNSL(arr,n,left);
    
    vector<int> width(n);
    for(int i=0;i<n; i++){
        width[i] = right[i] - left[i] - 1;
    }
    
    int maxArea = 0;
    
    for(int i=0; i<n; i++){
        // maxArea = max(maxArea,width[i]*arr[i]);
        if(maxArea < width[i]*arr[i])
            maxArea = width[i]*arr[i];
    }
    
    return maxArea;
    
}
/*You are required to complete this method*/
int maxArea(int M[MAX][MAX], int n, int m) {
    // Finding 1st row MAH
    int ans = MaH(M[0], m);
    // Now from second Row
    for(int i=1; i<n; i++){
        
        for(int j=0; j<m; j++)
            // If 1 is found add previous row on the same column value
            if(M[i][j] == 1){
                M[i][j] += M[i-1][j];
            }
    
        // ans = max(ans, MaH(M[i],m));
        int maxArea = MaH(M[i], m);
        if(ans < maxArea)
            ans = maxArea;
    }
    
    return ans;
}