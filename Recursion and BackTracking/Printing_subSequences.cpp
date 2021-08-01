#include <bits/stdc++.h>
using namespace std;
// ! TC: O(2^n) SC: O(n)-> outString
void av()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void printSubSequences(string s, string &outString, int index)
{

    if (index == s.size())
    {
        cout << outString << endl;
        outString.pop_back();
        return;
    }

    //include s[index]
    outString.push_back(s[index]);
    printSubSequences(s, outString, index + 1);

    //exclude s[index]
    printSubSequences(s, outString, index + 1);
}

int main()
{

    av();
    string str = "abc";
    string outString = "";
    printSubSequences(str, outString, 0);

    return 0;
}