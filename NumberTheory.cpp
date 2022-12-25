#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MULTIPLE_TEST int t;cin>>t;while(t--)
// #define mod 1000003

//local array size = 1e5, global = 1e8
//int = 1e9, long long = 1e18
// 1 sec = 1e7 ~ 1e8

const int N = 1e7+10;

//fact upto 1e7

//fill dp with -1
int dp[N];
int fact_precalc(int n, int mod){
    if(dp[n]!=-1) return dp[n]%mod;

    dp[0]=1;

    for (int i = 1; i <=n; i++)
    {
        dp[i]=(1LL*dp[i-1]*i)%mod;
    }

    return dp[n]%mod;
    
}

int fact(int n){
    int ans=1;
    for (int i = 1; i <=n; i++)
    {
        ans*=i;
    }
    return ans;
}


int fact_rec(int n , int mod){
    if(n==0) return 1;
    return (n*fact_precalc(n-1, mod))%mod;
}

int binpow_rec(int a, int b, int mod) {
    if (b == 0)
        return 1;
    int res = binpow_rec(a, b / 2,mod)%mod;
    if (b % 2)
        return (1LL*res * res * a)%mod;
    else
        return (1LL*res * res)%mod;
}

int binpow_iter(int a, int b, int mod) {
    //if a>1e18, eg a = 2^1024 a = binpow_iter(2,1024);
    a%=mod;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = (1LL*res * a)%mod;
        a = (1LL*a * a)%mod;
        b >>= 1;
    }
    return res%mod;
}

int modInverse(ll A, ll M)
{
    int g = __gcd(A, M);
    if (g != 1)
        return -1;
    else {
        // If a and m are relatively prime, then modulo
        // inverse is a^(m-2) mode m
        return binpow_iter(A, M - 2, M)%M;
    }
}



// for mod<=1e18 use binMultiply
int binMul(ll a, ll b, ll mod) {
    int ans = 0;
    while (b > 0) {
        if (b & 1)
            ans = (ans + a)%mod;
        a = (a + a)%mod;
        b >>= 1;
    }
    return ans%mod;
}

//O(log^2(N))
int binpow_large(ll a, ll b, ll mod) {  //mod<=1e18
    //if a>1e18, eg a = 2^1024 a = binpow_iter(2,1024);
    a%=mod;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = binMul(res,a,mod)%mod;
        a = binMul(a,a,mod)%mod;
        b >>= 1;
    }
    return res%mod;
}


//(a^b^c)mod M if gcd(a,m)==1 use mod-1, else use phi funtion

// a^b mod m= a^(b mod phi(m)) mod m
//phi(m)=m-1 for m being prime

ll triple_expo(ll a, ll b,ll c,ll mod){
    a%=mod;
    ll temp = binpow_iter(b,c,mod-1)%mod;
    return binpow_iter(a,temp,mod);
}

int phi(int n){
    int ret = n;

    for (int i = 2; i*i <=n; i++)
    {
        if(n%i==0){
            while(n%i==0){
                n/=i;
            }
            ret-= ret/i;
        }
    }
    
}

int phi_arr[N];
void phi_sieve(){
    for (int i = 1; i < N; i++)
    {
        phi_arr[i]=i;
    }
    for (int i = 2; i < N; i++)
    {
        if(phi_arr[i]==i){
            for (int j = i; j < N; j+=i)
            {
                phi_arr[j] -= phi_arr[j]/i;
            }
            
        }
    }
    
    
}





int combination(int n, int k,int mod){
    int num = fact_precalc(n,mod);
    int den = (1LL*(fact_precalc(k,mod)%mod)*(fact_precalc(n-k,mod)%mod))%mod;
    int inv = modInverse(den,mod);
    int ans = (1LL*num*inv)%mod;
    return ans;
}

vector<int> primes; //use sieve
int divisorCount(int n){
    int divisor = 1;
    for (int i = 0; i < primes.size(); i++)
    {
        if(n%primes[i]==0){
            int cnt=1;
            while(n%primes[i]==0){
                n/=primes[i];
                cnt++;
            }
            divisor*=cnt;
        }
    }
    return divisor;
}

int lcm(int a,int b){
    return (a/__gcd(a,b))*b;
}


int main(){

    fastio

    

return 0;
}
