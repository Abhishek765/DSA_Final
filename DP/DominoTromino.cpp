// ! DP solution - Time: O(N), Space: O(N)
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mod = 1e9 + 7;
    int dp[1001];
    int numTilings(int N)
    {

        //         Tabulation
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= N; i++)
        {
            dp[i] = (2 * dp[i - 1] % mod + dp[i - 3] % mod) % mod;
        }

        return dp[N] % mod;
    }
};