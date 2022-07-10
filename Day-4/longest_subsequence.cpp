#include<bits/stdc++.h>
using namespace std;
//Problem:Longest Consecutive Sequence
int longestConsecutive(vector<int>& nums) {
        //Logic:Insert array into the unordered_set,and traverse the array if (element-1) not exist
        // start with check (element+1) is present , increment count;
        unordered_set<int> s;
        for(auto i:nums){
            s.insert(i);
        }
        
        int ans=0;
        for(auto i:nums){
            if(s.find(i-1)==s.end()){
                int num=i;
                int streak=1;
                while(s.find(num+1)!=s.end()){
                    num+=1;
                    streak+=1;
                }
                ans=max(ans,streak);
            }
        }
        return ans;
    }
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int res=longestConsecutive(arr);
    cout<<res<<endl;
    return 0;
}