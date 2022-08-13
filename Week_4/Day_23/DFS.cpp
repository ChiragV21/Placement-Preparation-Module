//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int i, vector<int>&vi, vector<int>&ans, vector<int> adj[])
    {
        vi[i]=1;
        ans.push_back(i);
        for(auto it:adj[i])
        {
            if(!vi[it])
            {
                dfs(it, vi, ans, adj);
            }
        }
    }
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        // Code here
        vector<int>vi(v, 0);
        vector<int>ans;
        for(int i=0;i<v;i++)
        {
            if(!vi[i])
            {
                dfs(i, vi, ans, adj);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends