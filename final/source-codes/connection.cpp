#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    
    string s = "CODENECTION";

    int at = 0;
    vector<char> a(n);
    for(auto& i : a) cin >> i;

    for(auto& i : a){
        if (i == s[at]) at++;

        if (i == s.size()) break;
    }

    cout << (at == s.size() ? "YES" : "NO") << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}