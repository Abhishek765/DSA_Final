#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[1001][1001];
    //* 1st Approach: Top-down approach
    // int LCS(string x, string y, int n, int m){

    //     // base condition-> smaller valid input
    //     if(n == 0 || m == 0)
    //         return 0;

    //     // if answer already present at dp[n][m]
    //     if(dp[n][m] != -1)
    //         return dp[n][m];

    // // if last charater is same
    //     if(x[n-1] == y[m-1]){

    //         return dp[n][m] = 1 + LCS(x, y, n-1, m-1);
    //     }

    //   // if last charater is not equal
    //   return dp[n][m] = max(LCS(x, y, n-1, m), LCS(x, y, n, m-1));

    // }

    //* 2nd Approach: Bottom-Up
    //! TC: O(m*n)
    //! SC: O(m*n)
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

    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {

        return LCS(s1, s2, x, y);
    }
};