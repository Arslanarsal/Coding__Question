#include <bits/stdc++.h>
using namespace std;

string mergeAlternately(string word1, string word2)
{
    int i = 0;
    int j = 0;
    int n1 = word1.size();
    int n2 = word2.size();
    string ans = "";
    while (i < n1 && j < n2)
    {
        ans += word1[i];
        ans += word2[j];
        i++;
        j++;
    }
    while (i < n1)
    {
        ans += word1[i];
        i++;
    }
    while (j < n2)
    {
        ans += word2[j];
        j++;
    }
    return ans;
}

int main()
{

    return 0;
}