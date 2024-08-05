#include <iostream>
using namespace std;

// Function to calculate the kth child to be removed
long long calculateRemovedChild(long long totalChildren, long long kthChild)
{
    // Base case: if there's only one child left, it's the
    // one to be removed
    if (totalChildren == 1)
        return 1;
    // If k is less than or equal to half the total number
    // of children
    if (kthChild <= (totalChildren + 1) / 2)
    {
        // If 2*k is greater than the total number of
        // children, return the remainder of 2*k divided by
        // the total number of children
        if (2 * kthChild > totalChildren)
            return (2 * kthChild) % totalChildren;
        else
            // Otherwise, return 2*k
            return 2 * kthChild;
    }
    // Calculate the kth child to be removed for half the
    // total number of children
    long long temp = calculateRemovedChild(
        totalChildren / 2,
        kthChild - (totalChildren + 1) / 2);
    // If the total number of children is odd, return 2*temp
    // + 1
    if (totalChildren % 2 == 1)
        return 2 * temp + 1;
    // Otherwise, return 2*temp - 1
    return 2 * temp - 1;
}

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        long long totalChildren, kthChild;

        cin >> totalChildren >> kthChild;
        cout << calculateRemovedChild(totalChildren, kthChild) << "\n";
    }
}
