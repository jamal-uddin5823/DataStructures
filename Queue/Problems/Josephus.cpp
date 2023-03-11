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

void rec(vector<int>& arr, int i, int k){
    if(arr.size()==0) return;

    i = (i+k)%arr.size();

    arr.erase(arr.begin()+i);

    rec(arr,i,k);

}

int josephus(int n, int k){
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        arr[i]=i+1;
    }

    rec(arr,0,k);
    return arr[0]+1;
    
}


// int josephus(int n, int k){
//     if(n==1)
//         return 1;

//     return (josephus(n-1,k)+k-1)%n+1;
// }

int josephusUsingQ(int n, int k){
    queue<int> q;
    for (int i = 1; i <=n; i++)
    {
        q.push(i);
    }

    int ans = 0;
    while(!q.empty()){
        for (int i = 1; i <=k; i++)
        {
            ans = q.front();
            q.pop();

            if(i!=k){
                q.push(ans);
            }
            else break;
        }
        
    }
    return ans;
    
}

int main(){

    fastio

    cout<<josephusUsingQ(10,2)<<'\n';
    

    return 0;
}