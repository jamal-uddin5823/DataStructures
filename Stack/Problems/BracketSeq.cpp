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

bool matchingPair(char a, char b){
    if(a=='(' && b==')') return true;
    if(a=='{' && b=='}') return true;
    if(a=='[' && b==']') return true;
    return false;
}


bool isValidBracket(string s){
    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            st.push(s[i]);

        else if(s[i]==')' || s[i]=='}' || s[i]==']'){
            if(!matchingPair(st.top(),s[i]))
                return false;

            else
                st.pop();
        }
    }
    if(!st.empty()) return false;

    return true;
    
}

int main(){

    fastio

    cout<<isValidBracket("({");

    return 0;
}