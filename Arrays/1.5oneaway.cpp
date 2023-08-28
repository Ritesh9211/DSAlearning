#include<bits/stdc++.h>
using namespace std;

//three types of edit possible obe insert a character,remove a character,replace a character.
//check if they are one edit away;

//gfg solution
bool oneaway(string s1,string s2){
    int n=s1.size();
    int m=s2.size();
    if(abs(n-m)>1) return false;
    int count=0;
    int i=0,j=0;
    while(i<n && j<m){
        if(s1[i]!=s2[j]){
            if(count==1) return false; //more than 2unmatched
            if(n<m){
                j++;
            }
            else if(m<n){
                i++;
            }
            else{
                i++;j++;
            }
            count++;
        }
        else{
            i++;j++;
        }
    }
    if(i<n||j<m) count++; //if last char is extra
    if(count==1) return true;
    return false;
}

//own solution
// bool oneaway(string s1,string s2){
//     int n=s1.size();
//     int m=s2.size();
//     if(abs(n-m)>1) return false;
//     map<char,int>mp;
//     for(int i=0;i<n;i++){
//         mp[s1[i]]++;
//     }
//     int flag=0;
//     for(int i=0;i<m;i++){
//         if(mp[s2[i]]){
//             mp[s2[i]]--;
//             if(mp[s2[i]]==0) mp.erase(s2[i]);
//         }
//     }
//     if(mp.size()>1) return false;
//     return true;
// }

int main(){
    string s1,s2;
    s1="pale";
    s2="ake";
     if(oneaway(s1,s2)){
        cout<<"true"<<endl;
     }
     else{
        cout<<"false"<<endl;
     }
    return 0;
}