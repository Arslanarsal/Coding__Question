#include <bits/stdc++.h>
using namespace std;
string shortestBeautifulSubstring(string s, int k)
{
    int n = s.length();
    int head = 0, tail = 0, i = -1, j = -1, diff = INT_MAX, count = 0;
    for (head = 0; head < n; head++)
    {
        if (s[head] == '1')
        {

            count++;
        }
        while (count > k)
        {
            if (s[tail++] == '1')
            {
                count--;
            }
        }
        if (count == k)
        {
            int temp = (head - tail) + 1;
            if (temp < diff)
            {
                diff = temp;
                i = head;
                j = tail;
            }
        }
    }
    while (count == k && tail < head)
    {
        if (s[tail] == '1')
        {
            count--;
        }
        j = tail;
        tail++;
    }
    if (i == -1)
    {
        return "";
    }

    return s.substr(j, i);
}
int main()
{
    string s = "11000111";
    cout << shortestBeautifulSubstring(s, 1);

    return 0;
}