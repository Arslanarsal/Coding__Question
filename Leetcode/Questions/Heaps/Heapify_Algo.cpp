#include <bits/stdc++.h>
using namespace std;

// Function to heapify a subtree rooted at index i in a max-heap
void heapify(vector<int> &v, int n, int i)
{
    int largest = i;       // Assume the largest element is at the current root index
    int left = 2 * i + 1;  // Calculate the left child index
    int right = 2 * i + 2; // Calculate the right child index

    // Compare the left child with the largest element so far
    if (left < n && v[left] > v[largest])
    {
        largest = left;
    }

    // Compare the right child with the largest element so far
    if (right < n && v[right] > v[largest])
    {
        largest = right;
    }

    // If the largest element is not the root, swap the elements and heapify the affected subtree
    if (largest != i)
    {
        swap(v[i], v[largest]);
        heapify(v, n, largest);
    }
}

// Function to build a max-heap from a given vector of integers
void buildMaxHeap(vector<int> &v)
{
    int n = v.size(); // Get the size of the vector

    // Build the max-heap bottom-up starting from the last non-leaf node
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(v, n, i);
    }
}

int main()
{
    vector<int> v = {-1, 2000, 54, 53, 55, 52, 50, 100}; // Sample input vector
    buildMaxHeap(v);                                     // Build a max-heap from the input vector

    cout << "Max heap: ";
    for (const auto &i : v)
    {
        cout << i << " ";
    }

    return 0;
}
