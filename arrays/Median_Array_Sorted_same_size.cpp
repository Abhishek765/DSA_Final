#include<bits/stdc++.h>
using namespace std;
void av()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
int medianSortedArr(int a[], int b[],int n){

    int i=0,j=0;
    int count;
    int m1=-1,m2=-1;
    for(count=0;count<=n;count++){
        // reach the end of first array because elements of array "a" is smaller than b[0]
        if(i == n){
            m1 = m2;
            m2 = b[0];
            break;
        }

        // reach the end of second array because elements of array "b" is smaller than a[0]
        else if(j == n){
            m1 = m2;
            m2 = a[0];
            break;
        }

        if(a[i] <= b[j]){
            m1 = m2;
            m2 = a[i];
            i++;
        }
        else{
            m1 = m2;
            m2 = b[j];
            j++;
        }

    }
    return ((m1 + m2)/2);
}
int main(){
    
    av();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n],b[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
        }

        for(int i=0; i<n; i++){
            cin>>b[i];
        }

        int ans = medianSortedArr(a,b,n);
        cout<<ans<<endl;
        }
    return 0;
}