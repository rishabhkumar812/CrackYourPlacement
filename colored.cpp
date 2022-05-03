//https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/
class Solution {
public:
    bool winnerOfGame(string colors) {
        int n=colors.length();
        int cntA=0,cntB=0;
        int cnt=1,prev=colors[0];
        for(int i=1;i<n;++i)
        {
            if(colors[i]==prev) cnt++;
            else
            {
                if(prev=='A' and cnt-2>0) cntA+=(cnt-2);
                if(prev=='B' and cnt-2>0) cntB+=(cnt-2);
                cnt=1;
                prev=colors[i];
            }
        }
        if(prev=='A' and cnt-2>0) cntA+=(cnt-2);
        if(prev=='B' and cnt-2>0) cntB+=(cnt-2);
        return cntA>cntB;
    }
};
