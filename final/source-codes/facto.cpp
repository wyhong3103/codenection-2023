#include <bits/stdc++.h>
 
using namespace std;
 
const int MX = 2e6 + 5;
const int MOD = 1e9 + 7;
long long fact[MX];
 
long long modpow(long long n, long long p){
    if (!p) return 1;
    long long sq = modpow(n, p/2);
    sq = (sq * sq) % MOD;
    return (p % 2 ? n * sq : sq) % MOD;
}
 
long long ncr(long long n, long long r){
    return (fact[n] * modpow((fact[r] * fact[n-r]) % MOD, MOD-2)) % MOD;
}

void gen_fact(){
    fact[0] = 1;
    for(long long i=1; i < MX; i++){
        fact[i] = (fact[i-1] * i) % MOD;
    }
}
 
void solve(){
    long long n, m;
    cin >> n >> m;

    gen_fact();
 
    map<int,int> mp;
    for(long long i=2; i * i <= n; i++){
        while (n % i == 0){
            n /= i;
            mp[i]++;
        } 
    }

    if (n > 1) mp[n]++;
 
    long long res = 1;
    for(auto& i : mp){
        res = (res * ncr(m + i.second - 1, i.second)) % MOD;
    }
 
    cout << (res * modpow(2, m-1)) % MOD << '\n';
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
} 
