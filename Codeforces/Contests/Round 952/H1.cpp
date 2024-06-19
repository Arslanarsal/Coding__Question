#include <bits/stdc++.h>
using namespace std;

class dis_join
{
    int *parent;
    int *size;

public:
    dis_join(int n)
    {
        parent = new int[n];
        size = new int[n];
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int getparent(int val)
    {
        if (parent[val] == val)
        {
            return val;
        }
        return parent[val] = getparent(parent[val]);
    }

    void makeparent(int ui, int vi)
    {
        int p1 = getparent(ui);
        int p2 = getparent(vi);
        if (p1 != p2)
        {
            if (size[p1] < size[p2])
            {
                parent[p1] = p2;
                size[p2] += size[p1];
            }
            else
            {
                parent[p2] = p1;
                size[p1] += size[p2];
            }
        }
    }

    int getsize(int val)
    {
        return size[getparent(val)];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        char arr[n][m];
        dis_join ds(n * m);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];

                if (j != 0 && arr[i][j] == '#' && arr[i][j - 1] == '#')
                {
                    ds.makeparent(((m * i) + j), (m * i) + (j - 1));
                }

                if (i != 0 && arr[i][j] == '#' && arr[i - 1][j] == '#')
                {
                    ds.makeparent(((m * i) + j), (m * (i - 1)) + j);
                }
            }
        }

        long long ans = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            long long temp = 0;
            set<int> visit;
            for (int j = 0; j < m; j++)
            {
                if (arr[i][j] == '#')
                {
                    visit.insert(ds.getparent((m * i) + j));
                }
                else
                {
                    temp++;
                    if (i != 0 && arr[i - 1][j] == '#')
                    {

                        visit.insert(ds.getparent((m * (i - 1)) + j));
                    }
                    if (i != (n - 1) && arr[i + 1][j] == '#')
                    {

                        visit.insert(ds.getparent((m * (i + 1)) + j));
                    }
                }
            }
            for (auto &&it : visit)
            {
                temp += ds.getsize(it);
            }

            ans = max(ans, temp);
        }

        for (int j = 0; j < m; j++)
        {
            long long temp = 0;
            set<int> visit;
            for (int i = 0; i < n; i++)
            {
                if (arr[i][j] == '#')
                {
                    visit.insert(ds.getparent((m * i) + j));
                }
                else
                {
                    temp++;
                    if (j != 0 && arr[i][j - 1] == '#')
                    {
                        visit.insert(ds.getparent((m * (i)) + (j - 1)));
                    }

                    if (j != (m - 1) && arr[i][j + 1] == '#')
                    {
                        visit.insert(ds.getparent((m * (i)) + (j + 1)));
                    }
                }
            }
            for (auto &&it : visit)
            {
                temp += ds.getsize(it);
            }

            ans = max(ans, temp);
        }
        cout << ans << "\n";
    }
    return 0;
}