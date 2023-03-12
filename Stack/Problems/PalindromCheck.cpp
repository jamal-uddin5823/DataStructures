#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MULTIPLE_TEST int t;cin>>t;while(t--)
#define pi (2*acos(0.0))

//local array size = 1e5, global = 1e8
//int = 1e9, long long = 1e18
// 1 sec = 1e7 ~ 1e8

const int N = 1e7+10;

bool isPalin(string s){
    stack<char> st;

    for(auto x:s)
        st.push(x);
    
    string ans = "";
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    return ans==s;
}

int main(){

    fastio

    cout<<isPalin("abbabba")<<'\n';

    return 0;
}