#include <iostream>
using namespace std;

int firstIndex(int a[], int low, int high, int x,int n){
    
    if(low <= high){
        
        int mid = low + (high - low)/2;
        
        if((a[mid] == x) && (a[mid-1] < x || mid == 0))
        return mid;
        
       else if(a[mid] < x)
            return firstIndex(a, mid + 1, high,x,n);
        
        else 
            return firstIndex(a, low, mid - 1,x,n);
            
    }
    return -1;
}

int lastIndex(int a[], int low, int high, int x,int n){
    
    if(low <= high){
        
        int mid = low + (high - low)/2;
        
        if((a[mid] == x) && (a[mid + 1] > x || mid == n-1) )
            return mid;
        
        else if(a[mid] < x)
            return lastIndex(a, mid + 1, high,x,n);
        
        else
            return lastIndex(a, low, mid - 1,x,n);
        
    }
    return -1;
}
int main() {
    
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        int a[n];
        for(int i=0; i<n;i++)
            cin>>a[i];
        
        int first=-1,last=-1;
        
        // using Binary search
        first = firstIndex(a, 0, n-1,x,n);
        last = lastIndex(a, 0, n-1,x,n);
        
        if(first != -1)
            cout<<first<<" "<<last<<endl;
        else
            cout<<"-1\n";
        
    }
	return 0;
}