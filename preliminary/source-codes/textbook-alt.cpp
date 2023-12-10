#include <bits/stdc++.h>

using namespace std;

void solve(){
    long long n, m, k;
    cin >> n >> m >> k;

    cout << max((n * (n+1)/2) * m - k, 0LL);
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