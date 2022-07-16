#include<bits/stdc++.h>
using namespace std;
struct Job{
    int id,dead,profit;
};

bool compare(Job j1,Job j2){
    return j1.profit>j2.profit;
}

void JobScheduling(Job arr[],int n){
    sort(arr,arr+n,compare);
    int m=arr[0].dead;
    for(int i=1;i<n;i++){
        if(arr[i].dead>m){
            m=arr[i].dead;
        }
    }

    int slot[m+1];
    for(int i=0;i<=m;i++){
        slot[i]=-1;
    }

    vector<int> ans;
    int jobCount=0,jobProfit=0;
    for(int i=0;i<n;i++){
        for(int j=arr[i].dead;j>0;j--){
            if(slot[j]==-1){
                slot[j]=i;
                ans.push_back(arr[i].id);
                jobCount++;
                jobProfit+=arr[i].profit;
                break;
            }
        }
    }

    cout<<"Count of Jobs:"<<jobCount<<endl;
    cout<<"Profit:"<<jobProfit<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}

int main(){
    int n;
    cin>>n;
    int id[n],dead[n],profit[n];
    int j=1;
    for(int i=0;i<n;i++){
        id[i]=j;
        j++;
    }

    for(int i=0;i<n;i++){
        cin>>dead[i];
    }

    for(int i=0;i<n;i++){
        cin>>profit[i];
    }

    Job arr[n];
    for(int i=0;i<n;i++){
        arr[i].id=id[i];
        arr[i].dead=dead[i];
        arr[i].profit=profit[i];
    }

    JobScheduling(arr,n);
    return 0;
}