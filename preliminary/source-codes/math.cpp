#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    cout << -(n-(n != 0)) << ' ' << n << '\n';
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