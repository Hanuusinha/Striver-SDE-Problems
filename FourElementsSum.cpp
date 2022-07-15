#include <bits/stdc++.h> 
string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
    unordered_map<int,pair<int,int>> mp;
    for(int i = 0 ; i < n -1 ; i++)
    {
        for(int j = i+1 ; j < n ; j++)
        {
            int sum = arr[i]+ arr[j];
            mp[sum] = {i,j};
        }
    }
    for(int i = 0 ; i < n - 1 ; i++)
    {
        for(int j = i+1 ; j < n ; j++)
        {
            int left = target - (arr[i]+arr[j]);
            if(mp.find(left) != mp.end())
            {
                pair<int,int> t = mp[left];
                int t1 = t.first;
                int t2 = t.second;
                if(i != t1 && i != t2 && j!= t1 && j != t2)
                {
                    return "Yes";
                }
            }
        }
    }
    return "No";
}
