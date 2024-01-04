#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &nums)
{
    int a = 0, b = -1, c = nums.size() - 1;
    while (a <= c)
    {
        if (nums[a] == 2)
        {
            swap(nums[a], nums[c]);
            c--;
        }
        else if (nums[a] == 0)
        {
            swap(nums[a], nums[b]);
            a++;
            b++;
        }
        else
        {
            a++;
        }
    }
}

void display(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "  ";
    }
    cout << endl;
}

int main()
{
    vector<int> v = {2};
    sortColors(v);
    display(v);
    return 0;
}