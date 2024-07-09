#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void TwoSets(int n)
{
    // Calculate the total sum of numbers from 1 to n
    ll total_sum = (1ll * n * (1ll * n + 1)) / 2;

    // Check if the total sum is odd, if so, it's not
    // possible to divide into two equal halves
    if (total_sum % 2 != 0)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";

        // Initialize vectors for set1, set2, and a vector
        // to keep track of visited elements
        vector<int> set1, set2;
        vector<int> vis(n + 1, 0);

        // Initialize set1_sum and max_element
        ll set1_sum = 0;
        ll max_element = n;

        // Loop to fill set1
        while (set1_sum < total_sum / 2)
        {
            // Calculate remaining sum needed to make
            // set1_sum equal to total_sum / 2
            ll remaining_sum = total_sum / 2 - set1_sum;

            // If remaining_sum is greater than the maximum
            // element, add the maximum element to set1
            if (remaining_sum > max_element)
            {
                set1.push_back(max_element);
                vis[max_element] = 1;
                set1_sum += max_element;
                max_element--;
            }
            else
            {
                // If remaining_sum is less than or equal to
                // the maximum element, add remaining_sum to
                // set1
                set1.push_back(remaining_sum);
                vis[remaining_sum] = 1;
                set1_sum = total_sum / 2;
            }
        }

        // Loop to fill set2 with non-picked elements
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                set2.push_back(i);
            }
        }

        // Print the size and elements of set1
        cout << set1.size() << "\n";
        for (auto x : set1)
        {
            cout << x << " ";
        }
        cout << "\n";

        // Print the size and elements of set2
        cout << set2.size() << "\n";
        for (auto x : set2)
        {
            cout << x << " ";
        }
    }
}

// Driver Code
int main()
{
    int n;
    cin >> n;
    TwoSets(n);
}
