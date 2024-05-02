#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
    unordered_map<int, int> mp;
    stack<int> st;
    int n;

public:
    LRUCache(int capacity)
    {
        n = capacity;
    }

    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            return mp[key];
        }

        return -1;
    }

    void put(int key, int value)
    {
        if (st.size() == n)
        {
            mp.erase(st.top());
            st.pop();
        }
        mp[key] = value;
        st.push(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{

    return 0;
}