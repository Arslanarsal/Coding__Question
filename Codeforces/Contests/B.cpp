#include <bits/stdc++.h>
using namespace std;

<<<<<<< HEAD
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int aiza_moves = 0, bisma_moves = 0;

        // Count possible moves for Aiza and Bisma
        for (int i = 1; i < n - 1; i++)
        {
            if (s[i] == 'A' && s[i - 1] == 'A' && s[i + 1] == 'A')
            {
                aiza_moves++;
            }
            if (s[i] == 'B' && s[i - 1] == 'B' && s[i + 1] == 'B')
            {
                bisma_moves++;
            }
        }

        if (aiza_moves > bisma_moves)
        {
            cout << "aiza\n";
        }
        else
        {
            cout << "bisma\n";
        }
=======
// Function to convert the position to numeric indices
pair<int, int> convertPosition(const string &pos) {
    char letter = pos[0];
    int ringLevel = stoi(pos.substr(1));
    int ringIndex = letter - 'A'; // Convert 'A' to 0, 'B' to 1, ..., 'Z' to 25
    return {ringIndex, ringLevel};
}

// Function to calculate the cost
int calculateCost(const pair<int, int> &start, const pair<int, int> &end) {
    int startRing = start.first;
    int startLevel = start.second;
    int endRing = end.first;
    int endLevel = end.second;

    int totalCost = 0;

    // Move horizontally on the same ring level
    if (startRing == endRing) {
        totalCost = abs(startLevel - endLevel);
    } else {
        // Move vertically to the goal ring level
        int ringDistance = abs(startRing - endRing);
        int levelDistance = abs(startLevel - endLevel);

        // Total cost is the sum of moving to the correct ring level and moving to the correct level
        totalCost = (ringDistance * (ringDistance + 1)) / 2 + levelDistance;
    }

    return totalCost;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string start, end;
        cin >> start >> end;

        // Convert positions to numeric indices
        pair<int, int> startPos = convertPosition(start);
        pair<int, int> endPos = convertPosition(end);

        // Calculate and print the minimum cost
        cout << calculateCost(startPos, endPos) << endl;
>>>>>>> 612afbf91b3e5e60d4bf1d147177866db4ca57f6
    }
    return 0;
}
