//https://practice.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/1/#
class Solution{
  public:
    vector<int> find3Numbers(vector<int> arr, int n) {
        // Your code here
        int dp[3][n];
        dp[0][0]=arr[0];
        dp[1][0]=dp[2][0]=INT_MAX;
        for(int i=1;i<n;++i)
        {
            if(arr[i]<=dp[0][i-1])
            {
                dp[0][i]=arr[i];
                dp[1][i]=dp[1][i-1];
                dp[2][i]=dp[2][i-1];
            }
            else if(arr[i]<=dp[1][i-1])
            {
                dp[0][i]=dp[0][i-1];
                dp[1][i]=arr[i];
                dp[2][i]=dp[2][i-1];
            }
            else
            {
                int pos=0;
                while(dp[1][pos]!=dp[1][i-1]) pos++;
                return {dp[0][pos-1],dp[1][i-1],arr[i]};
            } 
        }
        return {};
    }
};

//Other solution using prefix and suffix sum is possible where for every element 
//we can store the smallest element on its left and largest element on its right.
