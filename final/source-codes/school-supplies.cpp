#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
int n;
map<string, int> vit;

void solve() {
    cin >> n;
    int ans = INF;
    for (int i = 0; i < n; i++) {
        int c;
        string s;
        cin >> c >> s;
        sort(s.begin(), s.end());

        if (vit.count(s) == 0) {
            vit[s] = c;
        } else {
            vit[s] = min(vit[s], c);
        }
    }

    auto getPrice = [&](string a, string b) {
        if (!vit.count(a) || !vit.count(b)) {
            return INF;
        }
        return vit[a] + vit[b];
    };

    if (vit.count("A") && vit.count("B") && vit.count("C")) {
        ans = vit["A"] + vit["B"] + vit["C"];
    }
    if (vit.count("ABC")) {
        ans = min(ans, vit["ABC"]);
    }

    ans = min(ans, getPrice("AB", "C"));
    ans = min(ans, getPrice("A", "BC"));
    ans = min(ans, getPrice("AC", "B"));
    ans = min(ans, getPrice("AB", "BC"));
    ans = min(ans, getPrice("AC", "BC"));
    ans = min(ans, getPrice("AC", "AB"));

    if (ans == INF) {
        ans = -1;
    }
    cout << ans << endl;
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
