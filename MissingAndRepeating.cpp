#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int xor1 = arr[0];
    int x = 0 , y = 0;
    int setBitNo;
    for(int i = 1 ; i < n ; i++)
    {
        xor1 = xor1 ^ arr[i];
    }
    for(int i = 1 ; i <= n ; i++)
    {
        xor1 = xor1 ^ i;
    }
    setBitNo = xor1 & ~(xor1-1);
    for(int i = 0 ; i < n ; i++)
    {
        if(arr[i] & setBitNo)
        {
            x = x ^ arr[i];
        }else{
            y = y ^ arr[i];
        }
    }
    for(int i = 1 ; i <= n ; i++)
    {
        if(i & setBitNo)
        {
            x = x ^ i;
        }else{
            y = y ^ i;
        }
    }
//     Count the occurrences of x and finding out which is missing and which is repeating
    int xcount = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(arr[i] == x)
        {
            xcount++;
        }
    }
    if(xcount == 0)
    {
        return {x,y};
    }
    return {y,x};
	
}
