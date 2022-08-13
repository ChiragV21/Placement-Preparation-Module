class Solution {
public:
    bool bipartite(int i, vector<vector<int>>&graph, vector<int>&color)
    {
        queue<int>q;
        color[i]=1;
        q.push(i);
        while(!q.empty())
        {
            int n=q.front();
            q.pop();
            for(auto it:graph[n])
            {
                if(color[it]==-1)
                {
                    color[it]=1-color[n];
                    q.push(it);
                }
                else if(color[it]==color[n])
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n, -1);
        //memset(color, -1, n);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(!bipartite(i, graph, color))
                    return false;
            }
        }
        return true;
    }
};