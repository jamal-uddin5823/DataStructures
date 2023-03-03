#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MULTIPLE_TEST int t;cin>>t;while(t--)

//local array size = 1e5, global = 1e8
//int = 1e9, long long = 1e18
// 1 sec = 1e7 ~ 1e8

const int N = 1e7+10;

int precedence(char c){
    if(c=='^') return 3;
    if(c=='*'||c=='/') return 2;
    if(c=='+'||c=='-') return 1;
    else return -1;
}



string in2Post(string& s){
    stack<char> st;

    string ans;

    for (int i = 0; i < s.length(); i++)
    {
        if((s[i]>='A' && s[i]<='Z')||(s[i]>='a' && s[i]<='z')||(s[i]>='0' && s[i]<='9')){
            ans.push_back(s[i]);
        }

        else if(s[i]=='(') st.push(s[i]);

        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                ans.push_back(st.top());
                st.pop();
            }
            if(!st.empty()) st.pop();
        }

        else{
            while(!st.empty() && precedence(st.top())>=precedence(s[i])){
                ans.push_back(st.top());
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
    
}

string in2Pre(string& s){
    int size = s.size();
    string ans;
    stack<char> st;

    for (int i = size -1; i >= 0; i--)
    {
        if((s[i]>='A' && s[i]<='Z')||(s[i]>='a' && s[i]<='z')||(s[i]>='0' && s[i]<='9')){
            ans.push_back(s[i]);
        }

        else if(s[i]==')'){
            st.push(s[i]);
        }

        else if(s[i]=='('){
            while(!st.empty() && st.top()!=')'){
                ans.push_back(st.top());
                st.pop();
            }
            st.pop();
        }

        else{
            while(!st.empty() && precedence(st.top())>precedence(s[i])){
                ans.push_back(st.top());
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin(),ans.end());
    return ans;

}

int main(){

    fastio

    string s;   cin>>s;

    cout<<in2Post(s)<<'\n';
    

return 0;
}
