#include <bits/stdc++.h>
using namespace std;

 /*
    Time Complexity: O(log(N))
    Space Complexity: O(1)

    where 'N' is the size of the heap.
*/

int pop(vector<int> &heap)
{
    if(heap.size()==0)return -1;
    // The top most element of heap is he largest.
    int ans=heap[0];

    // Removing the last element in heap and inserting it in top.
    heap[0]=heap.back();
    heap.pop_back();

    // Edge case.
    if(heap.size()==0)return ans;
    // Shifting the current element down till its correct position.
    int pos=0;
    while(true)
    {
        int left=pos*2+1;
        int right=pos*2+2;
        int leftvalue=0,rightvalue=0;

        // To avoid segementation fault.
        if(left<heap.size())leftvalue=heap[left];
        if(right<heap.size())rightvalue=heap[right];

        // Swapping it by the larger value.
        if(leftvalue<=heap[pos] && rightvalue<=heap[pos])
        {
            // As it is larger than both its children it is at its correct position.
            break;
        }
        else if(leftvalue>=rightvalue)
        {
            swap(heap[pos],heap[left]);
            pos=left;
        }
        else
        {
            swap(heap[pos],heap[right]);
            pos=right;            
        }
    }
    return ans;
}



// Code Snippet of the push function:

void push(vector<int> &heap, int x)
{
    heap.push_back(x);

    // Posistion of the current inserted element.
    int pos = heap.size() - 1;

    // Shifting the element up until it reaches the top most node if it is larger than its parent.
    while (pos > 0)
    {
        int parent = (pos - 1) / 2;
        if (heap[pos] > heap[parent])
        {
            swap(heap[parent], heap[pos]);
            pos = parent;
        }
        else
        {
            // As parent is larger the element now is in its correct position.
            break;
        }
    }
}

int main()
{
    vector<int> heap;
    push(heap, 2);
    push(heap, 5);
    push(heap, 1);
    push(heap, 9);
    cout << pop(heap) << endl;
    for (auto &&i : heap)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}