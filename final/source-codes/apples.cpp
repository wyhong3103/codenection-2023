#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(auto& i: a) cin >> i;

    vector<int> mod(m, -1);

    long long cur = 0;
    
    vector<int> ret;

    for(int i = 0; i < n; i++){
        cur += a[i];
        if (mod[cur % m] != -1){
            for(int j{mod[cur % m] + 1}; j <= i; j++){
                ret.push_back(j+1);
            }
            break;
        }
        if (cur % m == 0){
            for(int j{}; j <= i; j++){
                ret.push_back(j+1);
            } 
            break;
        }
        mod[cur % m] = i;
    }

    cout << ret.size() << '\n';
    for(auto& i : ret) cout << i << ' ';
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