#include <bits/stdc++.h>
 
using namespace std;


const int MX = 1e5 + 5;
vector<int> adj[MX];
 
void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(k);
    for(auto& i : a){
        cin >> i;
        i--;
    }

    for(int i = 0; i < m; i++){
        int f, t;
        cin >> f >> t;
        f--;t--;
        adj[f].push_back(t);
        adj[t].push_back(f);
    }

    vector<int> dist(n, INT_MAX);

    queue<int> q;

    for(auto& i : a){
        q.push(i);
        dist[i] = 0;
    }
    
    while (!q.empty()){
        int cur = q.front(); q.pop();

        for(auto& i : adj[cur]){
            if (dist[i] == INT_MAX){
                dist[i] = dist[cur] + 1;
                q.push(i);
            }
        }
    }

    long long sm = 0;
    for(int i = 0; i < n; i++){
        sm += dist[i];
    }

    cout << sm;
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
