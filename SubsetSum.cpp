void f(vector<int> &num,vector<int> &ans,int n , int i,int sum)
{
    if(i == n)
    {
        ans.push_back(sum);
        return;
    }
    f(num,ans,n,i+1,sum+num[i]);
    f(num,ans,n,i+1,sum);
    
}
vector<int> subsetSum(vector<int> &num)
{
    //Find out all the subsets of the given array and arrange them in ascending order:
    vector<int> ans;
    int n = num.size();
    
    f(num,ans,n,0,0);
    sort(ans.begin(),ans.end());
    return ans;
}
