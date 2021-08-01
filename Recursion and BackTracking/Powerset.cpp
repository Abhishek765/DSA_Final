#include <bits/stdc++.h>
using namespace std;
// ! TC: O(2^n) SC: O(n)-> out[] array space
class Solution
{
public:
    void powerSet(vector<int> &nums, vector<int> &out, vector<vector<int>> &res, int start, int n)
    {

        // base case
        if (start == n)
        {
            res.push_back(out);
            out.pop_back();
            return;
        }

        // including
        out.push_back(nums[start]);
        powerSet(nums, out, res, start + 1, n); // move forward

        // excluding
        powerSet(nums, out, res, start + 1, n); // move forward
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> out;
        vector<vector<int>> res;

        powerSet(nums, out, res, 0, nums.size());

        return res;
    }
};