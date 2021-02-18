// ! Time: O(n) 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
//     O(n) approach - Based on Observation we can form any number using just 2 and 3 if n > 4 then we can replace 2's with 3's how?? Ex 6- using 2's - 2*2*2 = 8 (as sum of three 2's give us 6) and if we use 3's 3*3 = 9 , so here means that we can chose 3's instead 2's wherever possible (actually if n > 4 it is possible ;)
    int integerBreak(int n) {
        
        if(n==2) return 1;
        
        if(n==3) return 2;
        
        long long prod = 1;
        
        while(n > 4){
            n -= 3;
            prod *= 3;
        }
        
        prod *= n;
        
        return prod;
    }
};