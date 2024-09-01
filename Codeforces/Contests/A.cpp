#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> findWinners(vector<vector<int>> &matches)
{
    // Map to count losses of each player
    map<int, int> lossCount;
    // Set to keep track of all players who have won at least one match
    set<int> winners;

    // Traverse each match
    for (const auto &match : matches)
    {
        int winner = match[0];
        int loser = match[1];

        // Add winner to the winners set
        winners.insert(winner);

        // Increment the loss count for the loser
        lossCount[loser]++;

        // Ensure winner is also in the loss count map with 0 losses
        if (lossCount.find(winner) == lossCount.end())
        {
            lossCount[winner] = 0;
        }
    }

    // Vectors to store players with no losses and exactly one loss
    vector<int> noLosses;
    vector<int> oneLoss;

    // Traverse the loss count map to populate noLosses and oneLoss
    for (const auto &entry : lossCount)
    {
        int player = entry.first;
        int losses = entry.second;

        if (losses == 0)
        {
            noLosses.push_back(player);
        }
        else if (losses == 1)
        {
            oneLoss.push_back(player);
        }
    }

    // Sort the result lists
    sort(noLosses.begin(), noLosses.end());
    sort(oneLoss.begin(), oneLoss.end());

    // Return the result
    return {noLosses, oneLoss};
}

int main()
{
    // Sample input
    vector<vector<int>> matches = {{1, 3}, {2, 3}, {3, 6}, {5, 6}, {5, 7}, {4, 5}, {4, 8}, {4, 9}, {10, 4}, {10, 9}};

    // Get the result
    vector<vector<int>> result = findWinners(matches);

    // Output the result
    for (const auto &players : result)
    {
        for (int player : players)
        {
            cout << player << " ";
        }
        cout << endl;
    }

    return 0;
}
