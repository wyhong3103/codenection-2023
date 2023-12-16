#include <bits/stdc++.h>
 
using namespace std;
 
void solve(){
    long long n, m;
    cin >> n >> m;

    vector<long long> a(n), b(m);
    for(auto& i : a) cin >> i;
    for(auto& i : b) cin >> i;

    pair<long long, long long> mn{INT_MAX, INT_MAX};
    pair<long long, long long> sm{};
    for(int i = 0; i < n; i++){
        mn.first = min(mn.first, a[i]);
        sm.first += a[i];
    }
    for(int i = 0; i < m; i++){
        mn.second = min(mn.second, b[i]);
        sm.second += b[i];
    }

    long long mx = 0;
    for(int i = 0; i < n; i++){
        mx += a[i] * m + sm.second;
    }

    cout << min(sm.first + n * mn.second, sm.second + m * mn.first) << ' ' << mx;
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
