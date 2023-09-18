#include <bits/stdc++.h>
using namespace std;

void display(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

// void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
// {
//     int len = n + m;
//     for (int i = 0; i < nums2.size(); i++)
//     {
//         nums1[m] = nums2[i];
//         m++;
//     }
//     int gap = (len / 2) + (len % 2);
//     while (gap > 0)
//     {
//         int left = 0;
//         int right = gap;
//         while (right < len)
//         {
//             if (nums1[left] > nums1[right])
//             {
//                 swap(nums1[left], nums1[right]);
//             }
//             left++;
//             right++;
//         }

//         int gap1 = (gap / 2) + (gap % 2);
//         if (gap == gap1)
//         {
//             return;
//         }
//         gap = gap1;
//     }
// }
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    for (int i = 0; i < nums2.size(); i++)
    {
        nums1[m] = nums2[i];
        m++;
    }
    sort(nums1.begin(), nums1.end());
}

int main()
{
    vector<int> v = {2};
    vector<int> v1 = {};
    merge(v, 1, v1, 0);
    display(v);

    return 0;
}