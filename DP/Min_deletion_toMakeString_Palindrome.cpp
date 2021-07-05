#include <bits/stdc++.h>
using namespace std;
//! TC: O(n*m)
//! SC: O(n*m)

class Solution
{

public:
    int dp[1001][1001];

    int LCS(string x, string y, int m, int n)
    {

        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                // intialization
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                    continue;
                }

                // if both character are equal
                if (x[i - 1] == y[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }

    int minimumNumberOfDeletions(string S)
    {
        int m = S.length();
        string revStr = S;
        reverse(revStr.begin(), revStr.end());

        int deletionCount = m - LCS(S, revStr, m, m);

        return deletionCount;
    }
};