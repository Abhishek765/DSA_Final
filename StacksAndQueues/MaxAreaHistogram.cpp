#include <bits/stdc++.h>
using namespace std;

void PerformNSR(long long a[],int n,vector<int>& right){
    
    stack<pair<long long,int>> s;
    
    for(int i=n-1; i>= 0; i--){
        
        if(s.empty()){
            right[i] = n;
        }
        else{
            
            while(!s.empty() && (s.top()).first >= a[i]){
                s.pop();
            }
            if(s.empty())
                right[i] = n;
            else
                right[i] = (s.top()).second;
        }
        
        s.push({a[i], i});
    }
}
void PerformNSL(long long a[],int n,vector<int>& left){
    
    stack<pair<long long,int>> s;
    
    for(int i=0; i<n; i++){
        
        if(s.empty()){
            left[i] = -1;
        }
        else{
            
            while(!s.empty() && (s.top()).first >= a[i]){
                s.pop();
            }
            if(s.empty())
                left[i] = -1;
            else
                left[i] = (s.top()).second;
        }
        
        s.push({a[i], i});
    }
}
// Function to return Maximum Rectangular area in a histogram
// arr[]: input array
// n: size of array
long getMaxArea(long long arr[], int n){
    // NSR
    vector<int> right(n);
    // NSL
    vector<int> left(n);
    
    PerformNSR(arr,n,right);
    
    PerformNSL(arr,n,left);
    
    vector<long long> width(n);
    for(int i=0;i<n; i++){
        width[i] = right[i] - left[i] - 1;
    }
    
    long maxArea = 1;
    
    for(int i=0; i<n; i++){
        // maxArea = max(maxArea,width[i]*arr[i]);
        if(maxArea < width[i]*arr[i])
            maxArea = width[i]*arr[i];
    }
    
    return maxArea;
    
}