#include <bits/stdc++.h>
using namespace std;
void av()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void PrintSpelling(int n, vector<string> &spelling)
{

    if (n == 0)
    {
        return;
    }

    PrintSpelling(n / 10, spelling);

    cout << spelling[n % 10] << " ";
}

int main()
{

    av();
    int n = 5123;
    vector<string> spelling = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    PrintSpelling(n, spelling);

    return 0;
}