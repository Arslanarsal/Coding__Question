#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        string op1 = "";
        string op2 = "";
        for (auto i : word1)
        {
            op1 += i;
        }
        for (auto i : word2)
        {
            op2 += i;
        }
        return op1 == op2;
    }
};

int main()
{

    return 0;
}