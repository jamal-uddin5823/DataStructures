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

string in2Post(string exp){
    string ans;
    stack<char> st;
    for(char c: exp){
        if(c>='0' && c<='9') ans.push_back(c);
        else if(c>='a' && c<='z') ans.push_back(c);
        if(c>='A' && c<='Z') ans.push_back(c);
        
        else if(st.empty()) st.push(c);
        else{
            if(c=='(') st.push(c);

            else if(c==')'){
                while(!st.empty() && st.top()!='('){
                    ans.push_back(st.top());
                    st.pop();
                }
                if(st.top()=='(') st.pop();
            }

            else if(c=='^'){
                st.push(c);
            }

            else if(c=='*'||c=='/'){
                if(st.top()=='+' || st.top()=='-') st.push(c);
                else if(st.top()=='^'|| st.top()=='/'||st.top()=='*'){
                    ans.push_back(st.top());
                    st.pop();
                    while(st.top()!='+' && st.top()!='-'){
                        ans.push_back(st.top());
                        st.pop();
                    }
                    st.push(c);
                }
            }
            
            else if(c=='+' || c=='-'){
                if(st.top()=='^'|| st.top()=='*'|| st.top()=='/'||st.top()=='+' || st.top()=='-'){
                    ans.push_back(st.top());
                    st.pop();
                    while(!st.empty()){
                        ans.push_back(st.top());
                        st.pop();
                    }
                    st.push(c);
                }
            }
        }


    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main(){

    fastio

    string a = "K+L-M*N+(O^P)*W/U/V*T+Q";
    string ans = in2Post(a);
    cout<<ans;
    

    return 0;
}