#include <iostream>
#include <vector>
using namespace std;

int friendGroup(int n, vector<int> &a)
{
    int odd = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!(a[i] & 1))
        {
            ans++;
            odd = 0; // Reset odd count for consecutive even numbers
        }
        else if (++odd == 2)
        {
            ans++;
            odd = 0; // Reset odd count after forming a group
        }
    }
    return ans;
}

int main()
{
    vector<int> a = {20, 37, 43, 23, 4, 29, 4, 24};
    cout << friendGroup(8, a);

    return 0;
}
