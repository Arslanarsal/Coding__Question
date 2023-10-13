#include <bits/stdc++.h>
using namespace std;

/*
   Time Complexity : O(N * Q)
   Space Complexity : O( 1 )

   Where 'N' is the array 'arr' length and 'Q' is the array 'query' length.
*/

vector<int> countGreater(vector<int> &arr, vector<int> &query)
{

    // Initialize integer variables 'n' and 'q' with arr.length and query.length respectively.
    int n = arr.size(), q = query.size();

    // Declare an integer array 'answer' of length 'q'.
    vector<int> answer(q, 0);

    for (int i = 0; i < q; i++)
    {
        int queryIndex = query[i];

        // Check for all the greater elements to the right.
        for (int j = queryIndex + 1; j < n; j++)
        {
            if (arr[j] > arr[queryIndex])
            {
                answer[i]++;
            }
        }
    }

    // Return 'answer'
    return answer;
}

int main()
{

    return 0;
}