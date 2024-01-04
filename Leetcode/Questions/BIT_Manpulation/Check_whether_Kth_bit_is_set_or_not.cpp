#include <bits/stdc++.h>
using namespace std;
vector<int> bitManipulation(int num, int i)
{
    vector<int> ans;
    ans.push_back((num >> (i - 1)) & 1);
    ans.push_back(num | (1 << (i - 1)));
    ans.push_back(num & (~(1 << (i - 1))));
    return ans;
}

bool isKthBitSet(int n, int k)
{
    // if ((n & 1 << (k - 1)))
    // {
    //     return 1;
    // }
    // return 0;

    // In One line
    return (n & 1 << (k - 1)) ? 1 : 0;
}

int main()
{
    // vector<int> v = bitManipulation(9, 3);
    // for (int i = 0; i < 3; i++)
    // {
    //     cout << v[i] << " ";
    // }

    cout << isKthBitSet(128, 7);

    return 0;
}