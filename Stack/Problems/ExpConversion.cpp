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

int power(int a, int b){
    ll ans = 1;
    for (int i = 0; i < b; i++)
    {
        ans*=1LL*a;
    }
    return ans;
}

int evaluatePre(string s){
    int a =0 ,b = 0;
    stack<int> st;
    if(s[s.size()-1]=='+'||s[s.size()-1]=='-'||s[s.size()-1]=='*'||s[s.size()-1]=='/'|| s[s.size()-1]=='^'){
        cout<<"Not a prefix\n";
        return INT_MIN;
    }

    for (int i = s.size() - 1; i >= 0; i--)
    {
        if(s[i]=='+' || s[i]=='-' ||s[i]=='*' ||s[i]=='/' || s[i]=='^' ){
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push((a)+(b));
                break;

            case '-':
                st.push((a)-(b));
                break;

            case '*':
                st.push((a)*(b));
                break;

            case '/':
                st.push((a)/(b));
                break;
            
            case '^':
                st.push(power((a),(b)));
            
            default:
                break;
            }
        }
        else{
            st.push(s[i]-'0');
        }
    }
    return st.top();
    
}

int evaluatePost(string s){
    int a = 0, b = 0;
    stack<int> st;

    if(!(s[s.size()-1]=='+'||s[s.size()-1]=='-'||s[s.size()-1]=='*'||s[s.size()-1]=='/'|| s[s.size()-1]=='^')){
        cout<<"Not a postfix\n";
        return INT_MIN;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]=='+' || s[i]=='-' ||s[i]=='*' ||s[i]=='/' || s[i]=='^' ){
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
 

            switch (s[i])
            {
            case '+':
                st.push((a)+(b));
                break;

            case '-':
                st.push((b)-(a));
                break;

            case '*':
                st.push((a)*(b));
                break;

            case '/':
                st.push((b)/(a));
                break;
            
            case '^':
                st.push(power((b),(a)));
            
            default:
                break;
            }
        }
        else{
            st.push(s[i]-'0');
        }
        
    }
    return st.top();


}

int main(){

    fastio

    string s;   cin>>s;
    string ans1 = in2Post(s);
    string ans2 = in2Pre(s);
    cout<<ans1<<'\n';
    cout<<ans2<<'\n';


    cout<<evaluatePost(ans1)<<'\n';
    cout<<evaluatePre(ans2)<<'\n';
    

return 0;
}
