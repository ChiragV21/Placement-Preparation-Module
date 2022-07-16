#include<bits/stdc++.h>
using namespace std;
int main(){
    int amount;
    cin>>amount;
    int amt=amount;
    int currency[]={1,2,5,10,20,50,100,200,500,2000};
    int n=sizeof(currency)/sizeof(currency[0]);
    sort(currency,currency+n,greater<int>());
    //Minimum count no of coins
    int coins=0;
    for(int i=0;i<n;i++){
        if(amount>=currency[i]){
            coins+=amount/currency[i];
            amount-=amount/currency[i]*currency[i];
        }
    }
    cout<<coins<<endl;

    amount=amt;
    //print coins
    vector<int> ans;
    for(int i=0;i<n;i++){
        while(amount>=currency[i]){
            amount-=currency[i];
            ans.push_back(currency[i]);
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}