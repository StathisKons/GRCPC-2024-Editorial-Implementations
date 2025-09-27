#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct DSU {
    vector<int> par;
    vector<int> size;
    vector<bool> magical;
    
    DSU(int n) : par(n + 1), size(n + 1, 1), magical(n + 1) {
        iota(par.begin() + 1, par.end(), 1);
    }

    int find(int a) {
        if(par[a] == a) return a;
        return par[a] = find(par[a]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if(a == b) return false;

        if(size[a] < size[b]) swap(a, b);

        size[a] += size[b];
        par[b] = a;
        if(magical[b]) magical[a] = true;

        return true;
    }

    void make_magical(int a) {
        a = find(a);
        magical[a] = true;
    }

    bool is_magical(int a) {
        a = find(a);
        return magical[a];
    }

    int get_size(int a) {
        a = find(a);
        return size[a];
    }
};

void solve(void){
    int n, m, c;
    cin >> n >> m >> c;
    
    DSU dsu(n);
        
    while(c--) {
        int a;
        cin >> a;
    
        dsu.make_magical(a);
    }

    vector<vector<int>> adj(n + 1);
    for(int i = 0 ; i < m ; i++){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int q;
    cin >> q;

    vector<int> withering(q);
    for(auto& i : withering) cin >> i;

    vector<bool> withered(n + 1);

    for(auto i : withering) withered[i] = true;
    
    for(int i = 1 ; i <= n ; i++){
        if(withered[i]) continue;
        
        for(auto u : adj[i]) {
            if(withered[u]) continue;
            
            dsu.unite(i, u);
        }
    }

    vector<int> ans(q);

    for(int i = q - 1 ; i >= 0 ; i--) {
        int v = withering[i];

        withered[v] = false;

        int tot = 1;
        for(auto u : adj[v]) {
            if(withered[u]) continue;

            int add = 0;
            if(!dsu.is_magical(u)) add = dsu.get_size(u);

            if(dsu.unite(u, v)) tot += add; 
        }

        if(dsu.is_magical(v)) ans[i] = tot;
    }

    for(auto i : ans) cout << i << "\n";
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    
    return 0;
}
