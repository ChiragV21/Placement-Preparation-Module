#include<bits/stdc++.h>
using namespace std;
//Day-1:SetZeroes
//Brute Approach
void setZeroes(vector<vector<int>>& matrix) {
    int rows=matrix.size(); 
    int cols=matrix[0].size();
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(matrix[i][j]==0){
                for(int k=0;k<rows;k++){
                    if(matrix[k][j]!=0){
                        matrix[k][j]=-99999999;
                    }
                }
                
                for(int k=0;k<cols;k++){
                    if(matrix[i][k]!=0){
                        matrix[i][k]=-99999999;
                    }
                }
            }
        }
    }
    
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(matrix[i][j]==-99999999){
                matrix[i][j]=0;
            }
        }
    }
}

//Better Approach
void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size(); 
        int cols=matrix[0].size();
        vector<int> d1(rows,-1);
        vector<int> d2(cols,-1);
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==0){
                    d1[i]=0;
                    d2[j]=0;
                }
            }
        }
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(d1[i]==0 or d2[j]==0){
                    matrix[i][j]=0;
                }
            }
        }
}

//Optimised Approach

void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size(); 
        int cols=matrix[0].size();
        int check=1;
        for(int i=0;i<rows;i++){
            if(matrix[i][0]==0)
                check=0;
            for(int j=1;j<cols;j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        
        for(int i=rows-1;i>=0;i--){
            for(int j=cols-1;j>=1;j--){
                if(matrix[0][j]==0 or matrix[i][0]==0)
                    matrix[i][j]=0;
            }
            if(check==0){
                matrix[i][0]=0;
            }
        }
}
    
int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> arr(m,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
        cout<<endl;
    }
    
    setZeroes(arr);
    for(auto i:arr){
        for(auto j:i){
            cout<<j<<" ";
        }
    }
    
}