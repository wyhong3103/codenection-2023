#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
 
    vector<pair<int,int>> a(n);
    for(auto& i : a) cin >> i.first >> i.second;
 
    vector<vector<long long>> dp(n+1, vector<long long> (2 * n + 1, LONG_LONG_MAX));
 
    dp[0][n] = 0;
    for(int i=1; i <= n; i++){
        for(int j=0; j < 2*n + 1; j++){

            if (dp[i-1][j] == LONG_LONG_MAX) continue;
            
            //buy it
            int w = min(2 * n, j + a[i-1].first);

            dp[i][w] = min(dp[i][w], dp[i-1][j] + a[i-1].second);
 
            //steal it
            if (j) dp[i][j-1] = min(dp[i][j-1], dp[i-1][j]);

        }
    }
 
    long long mn = LONG_LONG_MAX;
    for(int j=n; j <= 2*n; j++){
        mn = min(mn, dp[n][j]);
    }
 
    cout << mn;
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