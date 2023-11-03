#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(nums[i]);
    }
    for (int i = k; i < nums.size(); i++)
    {
        if (pq.top() < nums[i])
        {
            pq.pop();
            pq.push(nums[i]);
        }
    }
    return pq.top();
}

vector<int> kLargest(int arr[], int n, int k) {
    vector<int> result;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }
    
    for (int i = k; i < n; i++) {
        if (pq.top() < arr[i]) {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    while (!pq.empty()) {
        result.push_back(pq.top());
        pq.pop();
    }

    reverse(result.begin(), result.end());
    
    return result;
}


int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 7, 2, 5, 8, 9, 4};
    cout << findKthLargest(v, 3);

    return 0;
}