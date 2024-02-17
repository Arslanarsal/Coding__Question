#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int n = heights.size();
        priority_queue<int> pq;
        int i = 0;
        for (i; i < n - 1; i++)
        {
            if (heights[i] >= heights[i + 1])
            {
                continue;
            }

            int diff = heights[i + 1] - heights[i];
            if (bricks >= diff)
            {
                bricks -= diff;
                pq.push(diff);
            }
            else if (ladders)
            {
                if (!pq.empty())
                {
                    int maxi = pq.top();
                    if (bricks + pq.top() >= diff)
                    {
                        bricks += maxi;
                        bricks -= diff;

                        pq.pop();
                        pq.push(diff);
                    }
                }
                ladders--;
            }
            else
            {
                break;
            }
        }
        return i;
    }
};

int main()
{

    return 0;
}