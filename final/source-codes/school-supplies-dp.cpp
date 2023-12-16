#include <bits/stdc++.h>

using namespace std;

int transform(string s){
    return ((s.find('A') != string::npos) * 4) | ((s.find('B') != string::npos) * 2) | ((s.find('C') != string::npos) * 1);
}

void solve(){
    int n;
    cin >> n;

    vector<long long> dp(8, 1e9);

    dp[0] = 0;

    vector<pair<long long, string>> a;
    for(int i=0; i < n; i++){
        int c; string s;
        cin >> c >> s;
        a.push_back({c, s});
    }

    for(int i=1; i <= n; i++){
        for(int j=0; j < 8; j++){
            dp[j | transform(a[i-1].second)] = min(dp[j | transform(a[i-1].second)], dp[j] + a[i-1].first);
        }    
    }

    cout << (dp[7] != 1e9 ? dp[7] : -1);
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
