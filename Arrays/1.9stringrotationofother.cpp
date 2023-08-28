#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s1="waterbottle";
    string s2="erbottlewat";
    s1 = s1+s1;
    long long found = s1.find(s2);
    if (found != string::npos)  //to check if s1 has s2 as substring
        cout<<"True"<<endl;
    // cout << "First occurrence is " <<found << endl;
    else
        cout<<"False"<<endl;
}

int main(){

    solve();
    return 0;
}