#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    unordered_set<int> s;
    for(int i = 0 ; i < n ; i++)
    {
        s.insert(arr[i]);
    }
    int maxCount = 1;
    for(int i = 0 ; i < n ; i++)
    {
        if(s.find(arr[i]-1)  != s.end())
        {
            continue;
        }else{
            int currCount = 1;
            int k = 1; 
            while(s.find(arr[i]+k)!=s.end())
            {
                currCount++;
                k++;
            }
            maxCount = max(maxCount,currCount);
        }
    }
    return maxCount;
}
