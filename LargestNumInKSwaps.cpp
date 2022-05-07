//https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1/
//Question belongs to backtracking and not DP
/*
Similar ques:
Find maximum/minimum integer possible by doing "at-least K" swap operations on its digits.
Find maximum/minimum integer possible by doing "exactly K" swap operations on its digits.
*/
class Solution
{
    public:
    void findMax(int i,int k, string &str, string &ans)
    {
        if(k<=0) return;
        char maxM=*max_element(str.begin()+i,str.end());
        if(str[i]!=maxM)
            k--;
        int n=str.length();
        for(int j=i;j<n;++j)
        {
            if(str[j]==maxM)
            {
                swap(str[i],str[j]);
                ans=max(ans,str);
                findMax(i+1,k,str,ans);
                swap(str[i],str[j]);
            }
        }
    }
    
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       string ans=str;
       findMax(0,k,str,ans);
       return ans;
    }
};
