#include <iostream>
#include <cmath>
using namespace std;

int characterReplacement(string str, int k)
{
    int ans = 0;          // Stores the length of the longest repeating substring
    int n = str.length(); // Get the size of the input string
    int i = 0, j;         // 'i' points to the start of the window, and 'j' points to the end of the window
    int cnt[26] = {0};    // Stores the count of characters (A-Z)
    int mx = 0;           // Variable to store the maximum count of characters in the current substring

    for (j = 0; j < n; j++)
    {
        int x = str[j] - 'A'; // Convert the character to its corresponding index (0-25) in the 'cnt' array
        cnt[x]++;             // Increment the count of the current character
        mx = max(mx, cnt[x]); // Update the maximum count of characters in the current substring

        // Slide the window (from left) until the number of character changes allowed 'k' is satisfied
        while ((j - i + 1 - mx) > k)
        {
            int y = str[i] - 'A'; // Convert the character to its corresponding index (0-25) in the 'cnt' array
            cnt[y]--;             // Decrement the count of the character at the start of the window
            i++;                  // Move the start of the window to the right
        }

        // Update the length of the longest repeating substring found so far
        ans = max(ans, j - i + 1);
    }

    // Return the length of the longest repeating substring
    return ans;
}

int main()
{
    string s = "AABABBA";
    cout << characterReplacement(s, 1) << endl; // Calculate and print the result for the given string and k
    return 0;
}
