#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    map<char,int> mp;
    int ans = 0;
    int left = 0 , right = 0;
    while(right<input.size())
    {
        if(mp.count(input[right])!= 0)
        {
            left = max(mp[input[right]]+1,left);
        }
        mp[input[right]] = right;
        ans = max(ans,right-left+1);
        right++;
    }
    return ans;
    
    //Write your code here
}
