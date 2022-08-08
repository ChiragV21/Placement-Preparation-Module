// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         vector<int> ans;
//         unordered_map<int,int> m;
//         for(int &x:nums)
//             m[x]++;
        
//         priority_queue<pair<int,int>> q;
//         for(auto &x:m){
//             q.push({x.second,x.first});
//             if(q.size() > m.size()-k){
//                 ans.push_back(q.top().second);
//                 q.pop();
//             }
//         }
//         return ans;
//     }
// };

//MinHeap
class Solution {
public:
    #define pi pair<int,int>
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int &x:nums)
            m[x]++;
        
        priority_queue<pi,vector<pi>,greater<pi>> q;
        for(auto &x:m){
            q.push({x.second,x.first});
            if(q.size() > k)
                q.pop();
        }
        
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};