#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve(void){
    string s;
    cin >> s;

    int n = s.size();

    int m;
    cin >> m;

    vector<bool> can(n, false);
    while(m--){
        string st;
        cin >> st;
        
        for(int pos = s.find(st, 0) ; pos != s.npos ; pos = s.find(st, pos + st.size())){
            for(int i = pos ; i < pos + st.size() ; i++) can[i] = true;
        }
    }

    int ans = 0;
    for(int cur = 0, i = 0 ; i < n ; i++){
        if(can[i]) cur++;
        else cur = 0;

        ans = max(ans, cur);
    }

    cout << ans << "\n";
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    
    return 0;
}
