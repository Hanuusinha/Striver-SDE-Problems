#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    int count = 0 , xorr = 0;
    unordered_map<int,int> mp;
    for(auto it : arr)
    {
        xorr = xorr^it;
        if(xorr == x)
        {
            count++;
        }
        if(mp.find(xorr^x) != mp.end())
        {
            count += mp[xorr^x];
        }
        mp[xorr] += 1;
    }
    return count;
    //    Write your code here.
}
