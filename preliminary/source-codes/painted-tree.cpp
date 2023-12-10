#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

const int MX = 1e5 + 5;

long long fact[MX];

long long modpow(long long n, long long p){
    if (!p) return 1;
    long long sq = modpow(n, p/2);
    sq = (sq * sq) % MOD;
    return (p % 2 ? n * sq : sq) % MOD;
}

void gen_fact(){
    fact[0] = 1;
    fact[1] = 1;
    for(int i=2; i < MX; i++){
        fact[i] = (fact[i-1] * i) % MOD;
    }
}

long long ncr(long long n, long long r){
    long long num = (fact[n] * modpow(fact[n-r], MOD-2)) % MOD;;
    long long denom = fact[r];
    return (num * modpow(denom, MOD-2)) % MOD;
}

void solve(){
    long long n, m;
    cin >> n >> m;

    for(int i{}; i < n-1; i++){
        int a, b;
        cin >> a >> b;
    }

    if (!m){
        cout << 1;
        return;
    }

    long long b = -1;

    for(long long i{2}; i <= n; i++){
        if (i*(i-1)/2 == m){
            b = i;
        }
    }


    if (b == -1){
        cout << 0;
        return;
    }

    gen_fact();

    cout << ncr(n, b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--){
        solve();
    }
    return 0;
}
