#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        int n = hand.size();
        if (n % groupSize)
        {
            return false;
        }

        multiset<int> mp;
        for (auto &&i : hand)
        {
            mp.insert(i);
        }

        while (!mp.empty())
        {
            int item = *mp.begin();
            for (int i = 0; i < groupSize; i++)
            {
                if (!mp.count(item + i))
                {
                    return false;
                }
                mp.erase(mp.find(item + i));
            }
        }
        return true;
    }
};

int main()
{

    return 0;
}