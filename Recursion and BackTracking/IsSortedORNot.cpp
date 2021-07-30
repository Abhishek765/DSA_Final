#include <bits/stdc++.h>
using namespace std;
void av()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool isSorted(int arr[], int n, int index)
{
    if (index == n)
        return true;

    if (arr[index] < arr[index - 1])
        return false;

    return isSorted(arr, n, index + 1);
}

int main()
{

    av();
    int n = 5;
    int arr[] = {1, 6, 5, 12, 13};
    isSorted(arr, n, 1) ? cout << "Sorted" : cout << "Not Sorted";

    return 0;
}