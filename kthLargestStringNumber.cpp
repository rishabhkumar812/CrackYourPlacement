//https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/
class MyCmp
{
    public:
    bool operator() (string a,string b)
    {
        if(a.length()==b.length())
            return a>b;
        return a.length()>b.length();
    }
};
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string,vector<string>,MyCmp> pq;
        for(auto s:nums)
        {
            pq.push(s);
            if(pq.size()>k)
                pq.pop();
        }
        return pq.top();
    }
};
