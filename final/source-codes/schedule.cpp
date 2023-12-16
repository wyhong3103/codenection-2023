#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    cout << n << '\n';
    for(int i{}; i < n; i++){
        cout << i+1 << ' ' << (i-1 + n) % n + 1 << '\n';
    }
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