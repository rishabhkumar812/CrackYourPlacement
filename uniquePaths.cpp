//https://practice.geeksforgeeks.org/problems/number-of-unique-paths5339/1/
class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int a, int b)
    {
        int dp[a][b];
        memset(dp,0,sizeof(dp));
        dp[a-1][b-1]=1;
        for(int i=a-1;i>=0;--i)
        {
            for(int j=b-1;j>=0;--j)
            {
                if(j!=b-1) dp[i][j]+=dp[i][j+1];
                if(i!=a-1) dp[i][j]+=dp[i+1][j];
            }
        }
        return dp[0][0];
    }
};
