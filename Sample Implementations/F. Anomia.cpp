#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(void){
    int n, m, d;
    cin >> n >> m >> d;

    vector<string> v(n);
    for(auto& s : v) cin >> s;

    auto is_cop = [&](int i, int j) -> bool {
        return v[i][j] == 'v' || v[i][j] == '^' || v[i][j] == '<' || v[i][j] == '>';
    };

    auto out_of_bounds = [&](int i, int j) -> bool {
        return i < 0 || i >= n || j < 0 || j >= m;
    };


    // up, down, left, right
    const int di[] = {-1, 1, 0, 0};
    const int dj[] = {0, 0, -1, 1};

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            int dir;
            if(v[i][j] == '^') dir = 0;
            else if(v[i][j] == 'v') dir = 1;
            else if(v[i][j] == '<') dir = 2;
            else if(v[i][j] == '>') dir = 3;
            else continue;


            for(int ci = i + di[dir], cj = j + dj[dir], k = 0 ; k < d && !out_of_bounds(ci, cj) ; k++, ci += di[dir], cj += dj[dir]) {
                if(is_cop(ci, cj) || v[ci][cj] == '#') break;

                v[ci][cj] = '$';
            }
        }
    }

    int si, sj; 
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m ; j++) {
            if(v[i][j] == 'F') {
                si = i;
                sj = j;

                goto out;
            }
        }
    }

    cout << "NO\n";
    return;

out:

    bool vis[1000][1000] = {};
    auto dfs = [&](auto&& self, int i, int j) -> bool {
        if(out_of_bounds(i, j) || vis[i][j] || v[i][j] == '#' || v[i][j] == '$' || is_cop(i, j)) return false;

        vis[i][j] = true;

        if(v[i][j] == 'H') return true;

        for(int k = 0 ; k < 4 ; k++) {
            if(self(self, i + di[k], j + dj[k])) return true;
        }

        return false;
    };


    cout << (dfs(dfs, si, sj) ? "YES" : "NO") << "\n";
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    
    return 0;
}
