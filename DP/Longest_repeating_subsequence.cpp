#include <bits/stdc++.h>
using namespace std;

//! TC: O(m*n)
//! SC: O(m*n)
class Solution
{
public:
    int LCS(string x, string y, int n)
    {
        int dp[n + 1][n + 1];
        for (int i = 0; i <= n; i++)
        {

            for (int j = 0; j <= n; j++)
            {

                // base case intialization
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                    continue;
                }

                if (x[i - 1] == y[j - 1] && i != j)
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n][n];
    }

    int LongestRepeatingSubsequence(string str)
    {
        int m = str.size();
        return LCS(str, str, m);
    }
};