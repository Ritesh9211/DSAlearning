#include <bits/stdc++.h>
#define N 3
using namespace std;


void display(vector<vector<int>>&matrix){
    int n = matrix.size();
     for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
}

/*
     void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>ans(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[j][n-i-1]=matrix[i][j];
            }
        }
        matrix = ans;
        
    }

*/


void solve(vector<vector<int>>&matrix){
    int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){ //if j<n then matrix will be the original one
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
       display(matrix);
}

int main(){
    vector<vector<int>>arr={
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
   solve(arr);
    return 0;
}