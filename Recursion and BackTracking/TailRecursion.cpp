#include <bits/stdc++.h>
using namespace std;
void av()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
void tailRecursion(int n)
{

    // BC
    if (n == 0)
        return;

    // process
    cout << n << " ";

    return tailRecursion(n - 1);
}

void headRecursion(int n)
{

    // BC
    if (n == 0)
        return;

    // recursive call
    headRecursion(n - 1);

    cout << n << " ";
}

int main()
{

    av();
    int n = 5;
    tailRecursion(n);
    cout << endl;
    headRecursion(n);

    return 0;
}