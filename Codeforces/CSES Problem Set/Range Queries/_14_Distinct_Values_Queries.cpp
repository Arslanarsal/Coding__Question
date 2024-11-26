#include <bits/stdc++.h>
using namespace std;

struct BIT
{
    int size;
    vector<int> bit;
    BIT(int n) : size(n), bit(n + 1) {}
    void update(int x, int v)
    {
        x++;
        for (; x <= size; x += x & (-x))
        {
            bit[x] += v;
        }
    }
    
    int query(int b)
    {
        b++;
        int result = 0;
        for (; b > 0; b -= b & (-b))
        {
            result += bit[b];
        }
        return result;
    }
};
// EndCodeSnip

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    vector<vector<pair<int, int>>> queries(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        queries[a].push_back({b, i});
    }

    BIT bit(n);
    // last_index[val] is the left-most index where arr[last_index[val]] = val.
    map<int, int> last_index;
    vector<int> solution(q, -1);
    // Update the indices and answer queries from right to left.
    for (int i = n - 1; i >= 0; i--)

    {
        int val = arr[i];
        /*
         * If val already appeared earlier, then the saved value is no
         * longer the left-most index, so erase it from our BIT.
        */
        if (last_index.count(val) > 0)
            bit.update(last_index[val], -1);
        // i becomes the left-most index.
        last_index[val] = i;
        bit.update(i, 1);

        // Answer all queires with a == i.
        for (auto &qr : queries[i])
        {
            /*
             * The solution for this query is bit[i,b].
             * This equals bit[0,b] since bit[0,i-1] = 0.
             */
            solution[qr.second] = bit.query(qr.first);
        }
    }

    for (auto &a : solution)
    {
        cout << a << "\n";
    }
}