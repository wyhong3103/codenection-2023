#include <bits/stdc++.h>
 
using namespace std;
 
void solve(){
    long long n;
    cin >> n;

    string s = "I LOVE CODENECTION";
    if (n % 2) {
        reverse(s.begin(), s.end());
    }
    cout << s;
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