#include<bits/stdc++.h>
using namespace std;
struct Activities{
    int start;
    int finish;
    int pos;
};

bool compare(Activities i1,Activities i2){
    if(i1.finish<i2.finish) return true;
    else if(i1.finish<i2.finish){
        if(i1.pos<i2.pos)
            return true;
        else
            return false;
    }
    else
        return false;
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    int n=start.size();
    Activities arr[n];
    for(int i=0;i<n;i++){
        arr[i].start=start[i];
        arr[i].finish=finish[i];
        arr[i].pos=i+1;
    }
    
    sort(arr,arr+n,compare);
    
    int count=1;
    int limit=arr[0].finish;
    for(int i=1;i<n;i++){
        if(arr[i].start>=limit){
            limit=arr[i].finish;
            count++;
        }
    }
    return count;
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

    int res=maximumActivities(start,end);
    cout<<res<<endl;
    return 0;
}