#include <bits/stdc++.h>
using namespace std;

/*
   Time Complexity:O(n)
   Space Complexity:O(1)
*/

void heapify(vector<int> &arr, int n, int index)
{
    int largest = index;
    // If left child is greater than replace it with node
    if (2 * index + 1 < n && arr[largest] < arr[2 * index + 1])
    {
        largest = 2 * index + 1;
    }
    // If right child is greater than replace it with node
    if (2 * index + 2 < n && arr[largest] < arr[2 * index + 2])
    {
        largest = 2 * index + 2;
    }

    // If any child has more value call heapify on corresponding sub-tree.
    if (largest != index)
    {
        swap(arr[largest], arr[index]);
        heapify(arr, n, largest);
    }
}
vector<int> MinToMaxHeap(int n, vector<int> &arr)
{
    // Calling heapify process in bottom-up manner.
    for (int i = n / 2; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    return arr;
}

// ---------->>>>>>>>>>>>>>>>>>>>>>>>>>Second Way
void heapiy(vector<int> &arr, int indx)
{
    while (indx > 0)
    {
        int parent = (indx - 1) / 2;
        if (arr[indx] > arr[parent])
        {
            swap(arr[indx], arr[parent]);
            indx = parent;
        }
        else
        {
            break;
        }
    }
}

vector<int> MinToMaxHeap(int n, vector<int> &arr)
{
    for (int i = 0; i < n; i++)
    {
        heapiy(arr, i);
    }
    return arr;
}

int main()
{
    vector<int> v ={1,2,3,4,5,6,7,8,9};
    MinToMaxHeap(10,v);

    return 0;
}