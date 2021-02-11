// ! Time : O(n*(n^1/2)) and Space: O(n) - for dp[]
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int PerfectSqCount(int n, vector<int> dp)
    {
        //Using Tabulation method i.e filling from bottom to up
        //Base value when n==0 therefore my ans is 0
        dp[0] = 0;
        //Storing ans for each number from 1 to n
        for (int i = 1; i <= n; i++)
        {
            //getting the Perfect sq ex: for 12: loop repeats three times-> 1,2,3
            for (int j = 1; j * j <= i; j++)
            {

                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }

        // We got the ans at nth postion
        return dp[n];
    }
    int numSquares(int n)
    {
        //Creating dp arr
        vector<int> dp(n + 1, INT_MAX);

        return PerfectSqCount(n, dp);
    }
};