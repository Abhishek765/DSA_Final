// ! Time: O(max(m,n) + nlogn + mlogm) and Space is O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    void subSetSum(int arr[], int n, int range, vector<int> &candidates)
    {

        bool dp[n + 1][range + 1];
        // Initialization step
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= range; j++)
            {
                if (i == 0)
                    dp[i][j] = false;

                if (j == 0)
                    dp[i][j] = true;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= range; j++)
            {

                if (arr[i - 1] <= j)
                {
                    //    Two choices whether included or not included
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                }

                else // if element weight is greater than sum
                    dp[i][j] = dp[i - 1][j];
            }
        }

        // Getting the last row ans with having true value
        for (int i = 0; i <= range; i++)
        {

            if (dp[n][i] == true)
            {
                candidates.push_back(i);
            }
        }
    }
    int minDiffernce(int arr[], int n)
    {
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }

        vector<int> candidates;

        subSetSum(arr, n, sum, candidates);

        int mnRes = INT_MAX;

        for (int i = 0; i < candidates.size(); i++)
        {
            mnRes = min(mnRes, sum - 2 * candidates[i]);
        }

        return mnRes;
    }
};