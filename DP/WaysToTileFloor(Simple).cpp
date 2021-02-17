#include <bits/stdc++.h>
using namespace std;

// ! Three variables solution - Time: O(N), Space: O(1)
class Solution
{
public:
  int mod = 1e9 + 7;
  long long numberOfWays(long long N)
  {
    long long a = 1, b = 1;
    if (N <= 1)
      return 1;

    long long c;
    for (long long i = 2; i <= N; i++)
    {
      c = (a % mod + b % mod) % mod;
      a = b;
      b = c;
    }

    return c % mod;
  }
};

// ! DP solution - Time: O(N), Space: O(N)
class Solution
{
public:
  int mod = 1e9 + 7;
  long long dp[100001];
  long long numberOfWays(long long N)
  {
    if (N <= 1)
      return 1;

    dp[0] = 1;
    dp[1] = 1;

    for (long long i = 2; i <= N; i++)
    {
      dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[N];
  }
};