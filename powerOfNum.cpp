//https://practice.geeksforgeeks.org/problems/power-of-numbers-1587115620/1/
 class Solution
 {
    public:
    #define m 1000000007
    long long power(long long n,long long r)
    {
        if(r==0) return 1;
        long long ans=power(n,r/2)%m;
        ans=(ans*ans)%m;
        if(r&1) ans=(ans*n)%m;
        return ans;
    }
    
    long long power(int n,int r)
    {
        return power(n,r)%m;
    }
};
