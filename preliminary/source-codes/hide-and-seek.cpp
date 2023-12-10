#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for(auto& i : grid) cin >> i;

    for(int i{}; i < n; i++){
        for(int j{}; j < m; j++){
            if (grid[i][j] == '#'){
                cout << i+1 << ' ' << j+1;
                return;
            }
        }
    }

    cout << -1;
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