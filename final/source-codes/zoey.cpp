#include <bits/stdc++.h>
 
using namespace std;

const int MOD = 1e9 + 7;
const int MXN = 50 + 5;
const int MXK = 100 + 5;
long long dp[MXK][MXK][MXN][MXN];
 
void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    dp[0][1][0][0] = 1;
    for(int i{1}; i <= n+m; i++){
        for(int j{1}; j <= k; j++){
            for(int r{}; r <= n; r++){
                for(int c{}; c <= n; c++){
                    if (r == c){
                        dp[i][j][r][c] = (
                            dp[i-1][j-1][r-1][c] +
                            dp[i-1][j-1][r][c-1] +
                            dp[i-1][j-1][r][c] +
                            dp[i-1][j-1][r-1][c-1]
                        ) % MOD;
                    }else{
                        dp[i][j][r][c] = (
                            dp[i-1][j][r-1][c] +
                            dp[i-1][j][r][c-1] +
                            dp[i-1][j][r][c] +
                            dp[i-1][j][r-1][c-1]
                        ) % MOD;
                    }
                }
            }
        }
    }

    cout << dp[n+m][k][n][n] << '\n';
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
