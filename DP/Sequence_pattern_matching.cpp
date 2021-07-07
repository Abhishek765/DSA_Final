
#include <bits/stdc++.h>
using namespace std;

//! TC: O(m*n)
//! SC: O(m*n)
class Solution
{
public:
    int dp[1001][1001];
    int LCS(string x, string y, int n, int m)
    {

        for (int i = 0; i <= n; i++)
        {

            for (int j = 0; j <= m; j++)
            {

                // base case intialization
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                    continue;
                }

                if (x[i - 1] == y[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n][m];
    }

    bool seQuencePatternMatching(string s1, string s2)
    {

        int m = s1.length();
        int n = s2.length();

        if (LCS(s1, s2, m, n) == min(m, n))
        {

            return true;
        }

        return false;
    }
};