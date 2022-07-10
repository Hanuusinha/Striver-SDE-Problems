#include <bits/stdc++.h> 
int modularExponentiation(int x, int n, int m) {
	// Write your code here.
    int ans = 1;
    while(n)
    {
        if(n&1)
        {
            ans = (1LL*ans*x)%m;
        }
        x = (1LL*x*x)%m;
        n = n>>1;
    }
    return ans;
}
