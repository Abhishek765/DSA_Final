#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //!    TC: O(n) SC: O(n)
    //!     Top-down approach
    int countWays(int n, vector<int> &dp)
    {

        if (n < 0)
        {
            return 0;
        }

        if (n == 0)
            return 1;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = countWays(n - 1, dp) + countWays(n - 2, dp);
    }

    int climbStairs(int n)
    {

        vector<int> dp(46, -1);
        return countWays(n, dp);
    }

    //!    TC: O(n) SC: O(n)
    //!     Bottom-Up approach
    int climbStairs(int n)
    {

        vector<int> dp(46);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {

            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
