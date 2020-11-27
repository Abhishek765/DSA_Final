#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--){
	
	    int n; 
	    cin>>n;
	    int a[n*n];
	   // Min heap
	    priority_queue<int, vector<int>, greater<int>> pq;
	    for(int i=0;i<n*n;i++){
	        cin>>a[i];
	        pq.push(a[i]);
	    }
	    
	    while(!pq.empty()){
	        
	        cout<<pq.top()<<" ";
	        pq.pop();
	    }
	    cout<<endl;
	}
	return 0;
}