#include<algorithm>
bool cmp(pair<int,int> &p , pair<int,int> &q)
{
    double a = (double)p.second/p.first;
    double b = (double)q.second/q.first;
    return a>b;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(),items.end(),cmp);
    double finalVal = 0.0;
    int currWeight = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(currWeight+items[i].first<= w)
        {
            currWeight+=items[i].first;
            finalVal += items[i].second;
        }else{
            int remain = w - currWeight;
            finalVal += ((items[i].second/(double)items[i].first)*(double)remain);
            break;
        }
    }
    return finalVal;
}
