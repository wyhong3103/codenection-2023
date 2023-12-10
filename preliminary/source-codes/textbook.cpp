#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    long long sum = 0;
    long long current = m;
    for(int i=0; i < n; i++){
        sum += current;
        current += m;
    }

    cout << max(sum - k, 0LL);
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