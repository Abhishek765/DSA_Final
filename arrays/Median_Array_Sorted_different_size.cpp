#include<bits/stdc++.h>
using namespace std;
void av()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int medianSortedArr(int a[], int b[],int n1,int n2){

    int i=0,j=0;
    int count;
    int m1=-1,m2=-1;
    // if merged arr size is odd
    if((n1 + n2) %2 != 0){
        for(count=0;count<=(n1+ n2)/2;count++){
            
            if( i != n1 && j != n2){
                m1 = (a[i] < b[j]) ? a[i++] : b[j++]; 
            }

            else if(i < n1){
                m1 = a[i++];
            }
            else{
                m1 = b[j++];
            }
        }
        return m1;
    }else{
        // Even
       
        for(count = 0; count<= (n1 + n2)/2; count++){
            m2 = m1;

        if(i != n1 && j != n2){
            m1 = (a[i] < b[j])  ? a[i++] : b[j++];
        }
        else if(i < n1){
            m1 = a[i++];
        }
        else{
            m1 = b[j++];
        }

        }
        return (m1 + m2)/2;
    }
  
    return ((m1 + m2)/2);
}
int main(){
    
    av();
    int t;
    cin>>t;
    while(t--){
        int n1,n2;
        cin>>n1,n2;
        int a[n1],b[n2];
        for(int i=0; i<n1; i++){
            cin>>a[i];
        }

        for(int i=0; i<n2; i++){
            cin>>b[i];
        }

        int ans = medianSortedArr(a,b,n1,n2);
        cout<<ans<<endl;
        }
    return 0;
}