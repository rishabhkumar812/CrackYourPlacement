//https://leetcode.com/problems/maximum-performance-of-a-team/
class Solution {
public:
    #define pii pair<int,int>
    #define md 1000000007
    #define ll long long
    static bool cmp(pii a,pii b)
    {
        return a.second<b.second;
    }
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pii> arr(n);
        for(int i=0;i<n;++i)
            arr[i]={speed[i],efficiency[i]};
        
        sort(arr.begin(),arr.end(),cmp);
        
        vector<ll> suf(n);
        suf[n-1]=0;
        ll sm=0; 
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i=n-2;i>=0;--i)
        {
            sm+=arr[i+1].first;
            pq.push(arr[i+1].first);
            if(pq.size()>k-1)
            {
                sm-=pq.top();
                pq.pop();
            }
            suf[i]=sm;
        }
        
        ll ans=INT64_MIN;
        for(int i=0;i<n;++i)
        {
            ans=max(ans,((arr[i].first+suf[i])*arr[i].second));
        }
        return ans%md;        
    }
};
