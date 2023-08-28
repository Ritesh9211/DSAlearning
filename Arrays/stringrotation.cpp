#include <bits/stdc++.h>

using namespace std;

void rightrotaion(string str,int d)
{
    // judgling algorithm
    //optiomal way swap elements from 0 to d-1 and from d to n-1 and again whole string

    int n = str.size();
    for(int i=0;i<n;i++){
        if(i<d-i-1)
            swap(str[i],str[d-i-1]);
        else if(d+i<n-1-i){
            swap(str[d+i],str[n-1-i]);
        }
    }
    reverse(str.begin(),str.end());
    cout<<"Right Rotation--> "<<str<<endl;


}
void leftrotaion(string str,int d)
{
    //this is rightRotate by n-d
     int n = str.size();
     d=n-d;
    for(int i=0;i<n;i++){
        if(i<d-i-1)
            swap(str[i],str[d-i-1]);
        else if(d+i<n-1-i){
            swap(str[d+i],str[n-1-i]);
        }
    }
    reverse(str.begin(),str.end());
    cout<<"LeftRotation--> "<<str<<endl;;
}

int main(){
    string str="waterbottle";
    int d=3;
    leftrotaion(str,d);
    rightrotaion(str,d);
    return 0;
}