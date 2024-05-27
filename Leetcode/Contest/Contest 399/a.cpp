#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string compressedString(string word)
    {
        string st = "";

        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            int num = 1;
            while (num <= 9 && i < n - 1 && word[i + 1] == word[i])
            {
                num++;
                i++;
            }
            if (num == 10)
            {
                num--;
                i--;
            }

            string temp = to_string(num) + word[i];
            st += temp;
        }
        return st;
    }
};

int main()
{

    return 0;
}