#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    void display(vector<vector<int>>&matrix){
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m=matrix[0].size();
        int col=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    if(j!=0)
                        matrix[0][j]=0;
                    else
                        col=0;
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[0][j]==0||matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
            }
        }
        if(col==0){
            for(int i=0;i<n;i++){
                matrix[i][0]=0;
            }
        }
    display(matrix);
    }
};

Solution B;

int main(){
    vector<vector<int>>arr={{1,1,0},{0,1,0},{1,1,1}};
    B.setZeroes(arr);
    return 0;
}