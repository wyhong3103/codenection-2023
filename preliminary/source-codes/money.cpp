#include <bits/stdc++.h>

using namespace std;

void solve(){
    int k;
    string n; 
    cin >> k >> n;

    int len = k;

    vector<int> freq(len + 1);
    for(int i=0; i < k; i++){
        cin >> freq[i];
    }

    reverse(n.begin(), n.end());

    vector<int> need(len);

    for(int i=0; i < n.size(); i++){
        need[i] = n[i]-'0';
    }

    for(int i=0; i < len; i++){
        if (need[i]){
            if (freq[i] >= need[i]){
                freq[i] -= need[i];
                need[i] = 0;
            }else break;
        }

        if (freq[i]){
            freq[i+1] += freq[i]/10;
        }
    }

    bool ok = true;
    for(int i=0;i < n.size(); i++){
        ok &= need[i] == 0;
    }

    cout << (ok ? "YES" : "NO") << '\n';
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