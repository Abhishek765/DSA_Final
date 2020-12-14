// ! Time : O(nlogn)
// ! Space: O(n) -> inorder vector
// ! Approach -> Hint Minimum swaps to sort the arr
#include<bits/stdc++.h>
using namespace std;

void av()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
void inorder(int a[], int n, vector<int>& v,int index){
    // i->node, 2i + 1 ->left, 2i + 2 ->right (Complete tree case)
    // Base case (because index is increasing)
    if(index >= n) return;
    // Left
    inorder(a,n,v,2*index + 1);

    // Node
    v.push_back(a[index]);

    //Right 
    inorder(a,n,v,2*index + 2);
}

int minSwaps(vector<int> v, int n){

    // pair to store the element and its index
    vector<pair<int,int>> p(n);

    // Storing the element and index
    for(int i=0; i<n; i++){
        p[i].first = v[i];
        p[i].second = i;
    }
    // sort the p acc. to elements
    sort(p.begin(), p.end());

    // Visited arr to check whether the element is visited set to false initially
    vector<bool> vis(n, false);

    int swaps =0;

    for(int i=0; i<n; i++){

        // if ele is visited or it is already sorted -> skip
        if(vis[i] ||  p[i].second == i){
            continue;
        }
    
        // check for cycle 
        int j = i;
        int cycle_size =0;
        // Do until element jth element is not visited
        while(!vis[j]){

            // make it visited
            vis[j] = true;
            
            // Move to next node
            j = p[j].second;
            // Increase the no. of nodes in a cycle
            cycle_size++;
        }    

        if(cycle_size > 0){
            swaps += (cycle_size - 1);
        }

    }

    return swaps;

}
int main(){
    av();
    // Binary tree arr
    int a[] = {1,2,3}; /*
    
                        1
              BT->     / \
                      2   3
    */
    int n = sizeof(a)/sizeof(a[0]);
    
    vector<int> v;
    // Building a Inorder arr(of BT)
    inorder(a,n,v,0);

    // Now call min number swaps to sort the arr
    cout<< minSwaps(v,n);

    return 0;

}