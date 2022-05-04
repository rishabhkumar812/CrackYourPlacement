//https://leetcode.com/problems/guess-number-higher-or-lower-ii/
class Solution {
public:
    int getMoneyAmount(int n) {
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;++i)
        {
            for(int j=0;i+j<n;++j)
            {
                //dp[j][j+i]
                if(j==j+i) dp[j][j+i]=0;
                else
                {
                    int ans=min(j+1+dp[j+1][j+i],j+i+1+dp[j][j+i-1]);
                    for(int k=j+1;k<j+i;++k)
                    {
                        ans=min(ans,max(k+1+dp[j][k-1],k+1+dp[k+1][j+i]));
                    }
                    dp[j][j+i]=ans;
                }
            }
        }
        return dp[0][n-1];
    }
};
//Used MCM type dp for n^3 complexity
