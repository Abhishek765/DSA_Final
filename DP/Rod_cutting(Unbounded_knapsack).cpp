#include <bits/stdc++.h>
using namespace std;

// In knapsack we have wt[], val[] and W-> requried weight
int Unboundedknapsack(int price[], int len[], int n)
{
    // here prices == val, len == wt and n == W
    int dp[n + 1][n + 1];
    // initialization step
    for (int i = 0; i <= n; i++)
    {

        for (int j = 0; j <= n; j++)
        {

            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    // now start from 1,1
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // whether we can include the len or not
            if (len[i - 1] <= j)
            {

                // here we want maximum from including the len and not including
                dp[i][j] = max(price[i - 1] + dp[i][j - len[i - 1]],
                               dp[i - 1][j]);
            }
            else
            {
                // Not including
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][n];
}
int cutRod(int price[], int n)
{
    // Creating the len arr for possible lenght cuts
    int len[n];
    for (int i = 1; i <= n; i++)
    {
        len[i - 1] = i;
    }

    return Unboundedknapsack(price, len, n);
}