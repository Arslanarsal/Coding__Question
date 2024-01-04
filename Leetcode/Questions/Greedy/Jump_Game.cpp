#include <bits/stdc++.h>
using namespace std;

// Possible to reach to last index or not
bool canJump(vector<int> &nums)
{
    int flag = 0;
    int max_jump = 0;
    if (nums.size() == 1)
        return 1;
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (nums[i] == 0)
        {
            flag = 1;
        }
        if (flag == 1)
        {
            max_jump++;
            if (nums[i] >= max_jump)
            {
                flag = 0;
                max_jump = 0;
            }
        }
    }
    // cout<<max_jump;
    if (flag == 1)
        return 0;
    return 1;
}

// Maximum Jum to reach the last index
int jump(vector<int> &nums)
{
    int destination = nums.size() - 1;
    int coverage = 0;
    int jumps = 0;
    int lastjump = 0;
    if (nums.size() == 1)
    {
        return 0;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        coverage = max(coverage, i + nums[i]);
        if (i == lastjump)
        {
            jumps++;
            lastjump = coverage;

            if (coverage >= destination)
            {
                return jumps;
            }
        }
    }
    return jumps;
}

/*
    Time complexity: O(N)
    Space complexity: O(1)

    Where 'N' is the number of elements int the sequence.
*/
// This function give possible to reach or not and also if reach then minmim jump to reach send
int minJumps(vector<int> &arr, int n)
{

    /*
        The variable 'curEnd stores the last index reachable from the current index
        'curFarthest storest the farthest index reachable.
    */
    int minJump = 0, curEnd = 0, curFarthest = 0;
    for (int i = 0; i < n - 1; i++)
    {

        // Update 'curFarthest'.
        curFarthest = max(curFarthest, i + arr[i]);
        if (i == curEnd)
        {

            // Increment number of jumps if we reach the last reachable index.
            minJump++;

            // Update the farthest index reachable.
            curEnd = curFarthest;
        }
    }
    // Possible to reach.
    if (curFarthest >= n - 1)
        return minJump;
    else
        return -1;
}

int main()
{
    vector<int> v = {3, 2, 1, 0, 4};
    cout << canJump(v);

    return 0;
}