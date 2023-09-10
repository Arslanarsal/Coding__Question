#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    k = k % n;
    reverse(nums.begin(), nums.begin() + n - k);
    reverse(nums.begin() + n - k, nums.end());
    reverse(nums.begin(), nums.end());
}

void display(vector<int> vce)
{
    for (int i = 0; i < vce.size(); i++)
    {
        cout << vce[i] << "  ";
    }
    cout << endl;
}

int main()
{
    vector<int> v = {1, 2, 3};
    rotate(v, 3);
    display(v);

    return 0;
}