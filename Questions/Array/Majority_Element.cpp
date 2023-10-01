#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums)
{
    int ele, count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (count == 0 || ele == nums[i])
        {
            ele = nums[i];
            count++;
        }
        else
        {
            count--;
        }
    }
    count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (ele == nums[i])
        {
            count++;
        }
    }
    if (count > (nums.size() / 2))
    {
        return ele;
    }
    return -1;
}

vector<int> majorityElement3(vector<int> &nums)
{
    int ele1, ele2, count1 = 0, count2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (count1 == 0 && ele2 != nums[i])
        {
            count1++, ele1 = nums[i];
        }
        else if (count2 == 0 && ele1 != nums[i])
        {
            count1++, ele2 = nums[i];
        }
        else if (ele1 == nums[i])
        {
            count1++;
        }
        else if (ele2 == nums[i])
        {
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }
    count1 = 0;
    count2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (ele1 == nums[i])
        {
            count1++;
        }if (ele2 == nums[i])
        {
            count2++;
        }
    }
    vector<int> ans;
    if (count1 > nums.size() / 3)
    {
        ans.push_back(ele1);
    }
    if (count2 > nums.size() / 3)
    {
        ans.push_back(ele2);
    }
    return ans;
}

void display(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}

int main()
{
    vector<int> v = {3, 2, 3};
    // cout << majorityElement(v);

    // v = majorityElement3(v);
    // display(v);
    display(majorityElement3(v));

    return 0;
}