#include <iostream>
#include <vector>
#include <climits>
#include <string>
using namespace std;

// Function to find the minimum number of moves required
string find_minimum_moves(const vector<int> &case_data)
{
    // Parse the input for a single test case
    int S1 = case_data[0], F1 = case_data[1], H1 = case_data[2];
    int S2 = case_data[3], F2 = case_data[4], H2 = case_data[5];
    int S3 = case_data[6], F3 = case_data[7], H3 = case_data[8];

    int total_S = S1 + S2 + S3;
    int total_F = F1 + F2 + F3;
    int total_H = H1 + H2 + H3;

    vector<vector<string>> permutations = {
        {"S", "F", "H"},
        {"S", "H", "F"},
        {"F", "S", "H"},
        {"F", "H", "S"},
        {"H", "S", "F"},
        {"H", "F", "S"}};

    int min_moves = INT_MAX;
    string best_perm = "";

    for (const auto &perm : permutations)
    {

        int moves = 0;

        if (perm[0] == "S")
        {
            moves += (F1 + H1);
        }
        else if (perm[0] == "F")
        {
            moves += (S1 + H1);
        }
        else if (perm[0] == "H")
        {
            moves += (S1 + F1);
        }

        // Evaluate Stack 2
        if (perm[1] == "S")
        {
            moves += (F2 + H2);
        }
        else if (perm[1] == "F")
        {
            moves += (S2 + H2);
        }
        else if (perm[1] == "H")
        {
            moves += (S2 + F2);
        }

        // Evaluate Stack 3
        if (perm[2] == "S")
        {
            moves += (F3 + H3);
        }
        else if (perm[2] == "F")
        {
            moves += (S3 + H3);
        }
        else if (perm[2] == "H")
        {
            moves += (S3 + F3);
        }

        if (moves < min_moves)
        {
            min_moves = moves;
            best_perm = perm[0] + perm[1] + perm[2];
        }
    }

    return best_perm + " " + to_string(min_moves);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        vector<int> case_data(9);
        for (int i = 0; i < 9; ++i)
        {
            cin >> case_data[i];
        }

        cout << find_minimum_moves(case_data) << endl;
    }

    return 0;
}
