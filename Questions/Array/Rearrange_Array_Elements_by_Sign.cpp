#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int> &nums)
{
       int n=nums.size();
        vector<int>ans(n,0);
        int posIndex=0;
        int negIndex=1;
        for(auto it:nums){
            if(it>0){
                ans[posIndex]=it;
                posIndex+=2;
            }
            else{
                 ans[negIndex]=it;
                negIndex+=2;
            }
        }
        return ans;
    
}

void display(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v = {-37, -10, -9, 15, 14, 31};
    display(v);
     vector<int> ans =rearrangeArray(v);
    display(ans);

    return 0;
}