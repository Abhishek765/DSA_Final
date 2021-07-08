#include <bits/stdc++.h>
using namespace std;
//! TC: O(n^3)
//! SC: O(n^2)

class Solution
{
public:
    int dp[101][101];

    int solveMCM(int arr[], int i, int j)
    {

        // base condition
        // when i crosses j or when i==j
        if (i >= j)
            return 0;

        // if dp[i][j] has answer stored
        if (dp[i][j] != -1)
            return dp[i][j];

        int minCost = INT_MAX;
        // k loop from i to j-1
        for (int k = i; k < j; k++)
        {
            // when we multiply (AB)(CD)
            int costofMerge = arr[i - 1] * arr[k] * arr[j];
            // for each k division calculate tempAns
            int tempAns = solveMCM(arr, i, k) + solveMCM(arr, k + 1, j) + costofMerge;

            // storing minCost from all tempAns
            minCost = min(minCost, tempAns);
        }

        return dp[i][j] = minCost;
    }

    int matrixMultiplication(int N, int arr[])
    {
        memset(dp, -1, sizeof(dp));

        // i,j valid values from 1 to N-1
        return solveMCM(arr, 1, N - 1);
    }
};