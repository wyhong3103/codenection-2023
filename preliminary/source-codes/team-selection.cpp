#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<long long> a(n), s(n);

    for(int i=0; i < n; i++){
        cin >> a[i];
    }
    for(int i=0; i < n; i++){
        cin >> s[i];
    }

    vector<long long> pf_max(n);
    pf_max[0] = s[0];
    for(int i=1; i < n; i++){
        pf_max[i] = max(pf_max[i-1], s[i]);
    }

    long long sum = 0;
    for(int i=0; i < n; i++){
        sum += a[i] + pf_max[i];
    }
    
    cout << sum << '\n';
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