#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	        
	    int k;
	    cin>>k;
        int windowSize = 0;
        
        for(int i=0;i<n;i++)
            if(a[i] <= k)
                windowSize++;
                
        // 1st window
        int count = 0;
        for(int i=0;i<windowSize; i++){
            if(a[i] > k)
                count++;
        }
        
        int minSwaps = count;
       
        int y;
      for(int i=0, y=windowSize; y< n; i++,y++){
          if(a[i] > k)
            count--;
        // next  
          if(a[y] > k)
                count++;
        
            minSwaps = min(minSwaps, count);
      }
	   
	   
	   
	  cout<<minSwaps<<endl;
	}
	return 0;
}