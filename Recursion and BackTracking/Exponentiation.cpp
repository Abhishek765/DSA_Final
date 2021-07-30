#include <bits/stdc++.h>
using namespace std;
void av()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int exp(int n, int x)
{

    if (x == 0)
    {
        return 1;
    }

    int small_ans = exp(n, x / 2);

    if (x & 1)
    {
        // odd
        return n * small_ans * small_ans;
    }
    else
    {
        return small_ans * small_ans;
    }
}

int main()
{

    av();
    int n = 2;
    cout << exp(n, 5);

    return 0;
}