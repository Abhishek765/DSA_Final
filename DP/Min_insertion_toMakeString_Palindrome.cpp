#include <bits/stdc++.h>
using namespace std;
//! TC: O(n*m)
//! SC: O(n*m)

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

                if (x[i - 1] == y[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n][n];
    }

    int countMin(string str)
    {
        string revstr = str;
        reverse(revstr.begin(), revstr.end());

        return str.length() - LCS(str, revstr, str.length());
    }
};