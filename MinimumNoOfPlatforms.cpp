int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at,at+n);
    sort(dt,dt+n);
    int i = 1 , j = 0;
    int ans = 1 , currAns = 1;
    while(i<n && j < n)
    {
        if(at[i]<=dt[j])
        {
            currAns++;
            i++;
        }else if(at[i]>dt[j])
        {
            currAns--;
            j++;
        }
        if(currAns>ans)
        {
            ans = currAns;
        }
    }
    return ans;
    
    // Write your code here.
}
