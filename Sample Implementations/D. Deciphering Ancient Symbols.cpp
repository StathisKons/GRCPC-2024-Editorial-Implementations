#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(void){
    string s;
    cin >> s;
    int n = s.size();

    int m;
    cin >> m;
    vector<string> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];

    vector<bool> can(n);

    for (auto t : a) {
        for (int start = 0; start + t.size() <= n; start++) {
            bool ok = true;
            for (int i = start, j = 0; j < t.size(); i++, j++) {
                if (s[i] != t[j]) {
                    ok = false;
                    break;
                }
            }

            if (!ok) continue;

            for (int j = 0; j < t.size(); j++) {
                can[start + j] = true;
            }

            start = start + t.size() - 1;
        }
    }

    int ans = 0, cur = 0;
    for(int i = 0; i < n; i++){
        if(can[i]) {
            cur++;
        } else {
            ans = max(ans, cur);
            cur = 0;
        }
    }
 
    cout << max(ans, cur) << "\n";
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    
    return 0;
}
