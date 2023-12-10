#include <bits/stdc++.h>
 
using namespace std;
 
const int MX = 1e6 + 5;
int siz[MX];
int parent[MX];
    
int get(int a){
    return parent[a] = (parent[a] == a ? parent[a] : get(parent[a]));
}
 
bool merge(int a, int b){
    a = get(a);
    b = get(b);
    
    if (a == b) return false;
 
    if (siz[a] > siz[b]){
        parent[b] = a;
        siz[a] += siz[b];
    }else{
        parent[a] = b;
        siz[b] += siz[a];
    }
    return true;
}
 
void solve(){
    int n, m;
    cin >> n >> m;
 
    vector<int> id(n*m, -1);
 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int x;
            cin >> x;
            if (x <= n*m){
                id[x-1] = i*m + j;
            }
        }
    }
 
    unordered_set<int> prev;
 
    int mx = 0;
    for(int i = 0; i < n*m; i++){
        if (id[i] != -1) {
            siz[id[i]] = 1;
            parent[id[i]] = id[i];
 
            if (prev.count(id[i]-1)) merge(id[i], id[i]-1);
            if (prev.count(id[i]+1)) merge(id[i], id[i]+1);
            if (prev.count(id[i] - m)) merge(id[i], id[i]-m);
            if (prev.count(id[i] + m)) merge(id[i], id[i]+m);
 
            prev.insert(id[i]);
        }
        if (siz[get(id[0])] == i+1) mx = max(mx, i+1);
    }
    cout << mx;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}