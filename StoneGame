//https://leetcode.com/problems/stone-game/submissions/
class Solution {
public:
    #define ll long long
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<ll>> dp(n,vector<ll>(n));
        vector<ll> pre(n);
        pre[0]=piles[0];
        for(int i=1;i<n;++i) pre[i]=pre[i-1]+piles[i];
        
        for(int i=0;i<n;++i)
        {
            for(int j=0;i+j<n;++j)
            {
                // cout<<j<<','<<i+j<<' ';
                if(j==j+i) dp[j][j+i]=piles[j];
                else
                {
                    ll c1=piles[j]+pre[i+j]-pre[j]-dp[j+1][i+j];
                    ll c2=piles[i+j]+pre[i+j-1]-((j!=0)?pre[j-1]:0)+dp[j][i+j-1];
                    dp[j][j+i]=max(c1,c2);
                }
            }
            cout<<endl;
        }
        return dp[0][n-1]>pre[n-1]-dp[0][n-1];
    }
};
