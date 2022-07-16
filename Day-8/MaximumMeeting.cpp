#include<bits/stdc++.h>
using namespace std;
struct Meeting{
    int start;
    int end;
    int pos;
};

bool compare(Meeting m1,Meeting m2){
    if(m1.end<m2.end) return true;
    else if(m1.end==m2.end){
        return m1.pos<m2.pos;
    }
    else
        return false;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    vector<int> ans;
    int n=start.size();
    Meeting meet[n];
    for(int i=0;i<n;i++){
        meet[i].start=start[i];
        meet[i].end=end[i];
        meet[i].pos=i+1;
    }
    
    sort(meet,meet+n,compare);
    
    int endLimit=meet[0].end;
    ans.push_back(meet[0].pos);
    for(int i=1;i<n;i++){
        if(meet[i].start>endLimit){
            endLimit=meet[i].end;
            ans.push_back(meet[i].pos);
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> start(n);
    vector<int> end(n);
    for(int i=0;i<n;i++){
        cin>>start[i];
    }

    for(int i=0;i<n;i++){
        cin>>end[i];
    }

    vector<int> res=maximumMeetings(start,end);
    for(auto i:res){
        cout<<i<<" ";
    }
    return 0;
}