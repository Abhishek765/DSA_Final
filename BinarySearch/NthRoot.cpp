#include <bits/stdc++.h>
using namespace std;
// ! TC: O(nlog( x*(10^d) )) -> nth root of a number x with d decimal places accuracy
class NthRoot
{
private:
    double eps = 1e-6;

public:
    double multiply(double mid, int n)
    {
        double ans = 1;
        for (int i = 0; i < n; i++)
            ans *= mid;

        return ans;
    }

    double CalculateNthRoot(double x, int n)
    {
        double low = 1, high = x, mid;

        while (high - low > eps)
        {
            mid = (low + high) / 2;

            if (multiply(mid, n) < x)
                low = mid;
            else
                high = mid;
        }

        return low;
    }
};

int main()
{
    NthRoot ob;
    double ans = ob.CalculateNthRoot(4, 2);

    cout << ans << endl;

    return 0;
}