#include <bits/stdc++.h>
using namespace std;

class FoodRatings
{
public:
    bool comp(pair<int, string> l, pair<int, string> r)
    {
        if (l.first != r.first)
        {
            return l.first > r.first;
        }
        else
        {
            return l.second < r.second;
        }
    }
    unordered_map<string, set<pair<int, string>, comp>> mp;

    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
    }

    void changeRating(string food, int newRating)
    {
    }

    string highestRated(string cuisine)
    {
    }
};

int main()
{

    return 0;
}