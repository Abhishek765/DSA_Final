#include <bits/stdc++.h>
using namespace std;
//! TC: O(n*m)
//! SC: O(n*m)

int dp[1001][1001];
void lcs(string x, string y, int n, int m)
{

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {

            // initialization
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
                continue;
            }

            // if equal characters
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
}

string printSCSubSequence(string x, string y, int n, int m)
{
    string ans;

    // staring from n,m
    int i = n, j = m;

    while (i > 0 && j > 0)
    {
        // if both characters are equal
        if (x[i - 1] == y[j - 1])
        {
            // add to ans and go diagonally Up
            ans.push_back(x[i - 1]); // or y[j-1]
            i--;
            j--;
        }
        else
        {
            // go to the maximum side
            if (dp[i][j - 1] > dp[i - 1][j])
            {
                ans.push_back(y[j - 1]);
                j--;
            }
            else
            {
                ans.push_back(x[i - 1]);
                i--;
            }
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{

    string s1, s2;
    cout << "Enter strings\n";
    cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();

    // do LCS and get the table
    lcs(s1, s2, n, m);
    cout << "SCS length: " << (m + n) - dp[n][m] << endl;

    cout << "SCS: " << printSCSubSequence(s1, s2, n, m) << endl;

    return 0;
}