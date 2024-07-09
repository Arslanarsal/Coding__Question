#include<bits/stdc++.h>
using namespace std;

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class dsu {
    vector<int> parent;
    vector<int> size;

public:
    dsu(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            size[i] = 1;
            parent[i] = i;
        }
    }

    int get_p(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = get_p(parent[i]);
    }

    void make_p(int u, int v) {
        int pu = get_p(u);
        int pv = get_p(v);
        if (pu == pv) {
            return;
        }

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        unordered_map<int, vector<int>> adj;
        for (auto&& it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        unordered_map<int, vector<int>> num;
        for (int i = 0; i < n; i++) {
            int val = vals[i];
            num[val].push_back(i);
        }

        // Transform unordered_map to vector of pairs for sorting
        vector<pair<int, vector<int>>> sorted_num(num.begin(), num.end());
        sort(sorted_num.begin(), sorted_num.end());

        dsu ds(n);
        int ans = n;
        
        for (auto&& it : sorted_num) {
            vector<int> temp = it.second;
            int value = it.first;
            for (auto&& nei : temp) {
                for (auto&& j : adj[nei]) {
                    if (vals[j] <= value) {
                        ds.make_p(nei, j);
                    }
                }
            }
            
            unordered_map<int, int> component_size;
            for (auto&& i : temp) {
                int root = ds.get_p(i);
                component_size[root]++;
            }

            for (auto&& [root, size] : component_size) {
                ans += (size * (size - 1)) / 2;
            }
        }

        return ans;
    }
};


int main()
{
    
    return 0;
}