#include <bits/stdc++.h>
using namespace std;

string largestOddNumber(string num)
{
    int ans = 0;
    int n = num.size()-1;
    cout<<n<<endl;
    for (int i = n; i >= 0; i--)
    {
        if ((num[i] - '0') & 1)
        {
            return num.substr(0, i+1);
        }
    }
    return "";
}

int main()
{
    cout << largestOddNumber("252456888888");

    return 0;
}