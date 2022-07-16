#include<bits/stdc++.h>
using namespace std;
int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at,at+n);
    sort(dt,dt+n);
    int platform=1,result=1;
    int i=1,j=0;
    while(i<n and j<n){
        if(at[i]<=dt[j]){
            platform++;
            i++;
        }
        
        else{
            platform--;
            j++;
        }
        
        if(platform>result)
            result=platform;
    }
    return result;
}
int main(){
    int n;
    cin>>n;
    int at[n],dt[n];
    for(int i=0;i<n;i++){
        cin>>at[i];
    }

    for(int i=0;i<n;i++){
        cin>>dt[i];
    }

    int ans=calculateMinPatforms(at,dt,n);
    cout<<ans<<endl;
    return 0;
}