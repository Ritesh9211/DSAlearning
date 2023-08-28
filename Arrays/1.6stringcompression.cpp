#include <bits/stdc++.h>

using namespace std;

string solve()
{
    string str = "aabbccccd";
    int n = str.size();
    int cnt=1;
    char pre=str[0], curr;
    // vector<char>ans;
    string ans;
    for(int i=1;i<n;i++){
        curr = str[i];
        if(curr==pre){
            cnt++;
            pre=curr;
        }
        else{
            ans+=pre;
            ans+='0'+cnt;
            // ans.push_back(pre);
            // ans.push_back('0'+cnt);
            cnt=1;
            pre=curr;
        }
    }
    ans+=str[n-1];
    ans+='0'+cnt;
//    ans.push_back(str[n-1]);
//    ans.push_back('0'+cnt);
    if(ans.size()>str.size()) return str;
    return ans;
}

int main(){

    string ans= solve();
    cout<<ans<<endl;
    return 0;
}