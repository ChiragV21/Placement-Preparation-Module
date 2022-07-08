#include<bits/stdc++.h>
using namespace std;
int merge(vector<int> arr,int l,int mid,int r){
    int inv=0;
    int n1=mid-l+1;
    int n2=r-mid;
    int a[n1],b[n2];
    for(int i=0;i<n1;i++){
        a[i]=arr[l+i];
    }
    
    for(int i=0;i<n2;i++){
        b[i]=arr[mid+i+1];
    }
    
    int i=0,j=0,k=l;
    while(i<n1 and j<n2){
        if(a[i]<=b[j]){
            arr[k++]=a[i++];
        }
        else{
            inv+=n1-i;
            arr[k++]=b[j++];
        }
    }
    while(i<n1){
        arr[k++]=a[i++];
    }
    
    while(j<n2){
        arr[k++]=b[j++];
    }
    return inv;
}

int mergeSort(vector<int> arr,int l,int r){
    int inversion=0;
    if(l<r){
        int mid=(l+r)/2;
        inversion+=mergeSort(arr,l,mid);
        inversion+=mergeSort(arr,mid+1,r);
        inversion+=merge(arr,l,mid,r);
    }
    return inversion;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=mergeSort(arr,0,n-1);
    cout<<ans<<endl;
    return 0;
}