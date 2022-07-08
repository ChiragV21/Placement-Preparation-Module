#include<bits/stdc++.h>
using namespace std;
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    pair<int,int> ans;
    vector<int> freq(n+1,0);
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    
    for(int i=1;i<=n;i++){
        if(freq[i]==0){
            ans.first=i;
        }
        if(freq[i]>1){
            ans.second=i;
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
    pair<int,int> ans=missingAndRepeating(arr,n);
    cout<<"Missing Number is:"<<ans.first<<endl;
    cout<<"Repeating Number is:"<<ans.second<<endl;
    return 0;
}
