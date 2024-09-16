#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int rounds = 0;
    int expected = 1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == expected) {
            expected++;
        }
        // If the expected number doesn't increase, it means we need another round
        if (i == n - 1 || arr[i] >= expected) {
            rounds++;
        }
    }

    cout << rounds << endl;

    return 0;
}
