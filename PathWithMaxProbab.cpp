//https://leetcode.com/problems/path-with-maximum-probability/
//Solution includes 2 imp things 1. use of dijkstra for maximum cost 2. log values to avoid precision error in multiplication
class Solution {
public:    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();++i)
        {
            auto v=edges[i];
            int a=v[0],b=v[1];
            adj[a].push_back({b,log(succProb[i])});
            adj[b].push_back({a,log(succProb[i])});
        }
        vector<double> cost(n,-DBL_MAX);
        priority_queue<pair<double,int>> pq;
        cost[start]=DBL_MAX;
        pq.push({0,start});
        while(!pq.empty())
        {
            auto p=pq.top();
            pq.pop();
            for(auto p2:adj[p.second])
            {
                
                if(p.first+p2.second>cost[p2.first])//Dijkstra for maximising the log cost
                {
                    cost[p2.first]=p.first+p2.second;
                    pq.push({cost[p2.first],p2.first});
                }
            }
        }        
        return exp(cost[end]);                                        
    }
};
