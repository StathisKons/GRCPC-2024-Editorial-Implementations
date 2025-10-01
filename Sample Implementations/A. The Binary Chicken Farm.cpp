#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
int l;
 
string to_binary_string(int n) {
    string s;
    
    while (n) {
        if (n % 2 == 1) {
            s += '1';
        } else {
            s += '0';
        }
        n /= 2;
    }
 
    while (s.size() < l) s += '0';
    
    reverse(s.begin(), s.end());
    return s;
}
 
int to_decimal(string s) {
    int n = 0;
 
    for (int i = 0; i < s.size(); i++) {
        n *= 2;
        n += (s[i] - '0');
    }
 
    return n;
}
 
void solve(void){
    int n, m, k;
    cin >> n >> m >> k;
 
    vector<int> inf_by(n, -1);
    vector<vector<int>> eggs(2, vector<int>(n));

    int r = 0, w = 1;
 
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        l = s.size();
        eggs[0][i] = to_decimal(s);
    }
 
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        inf_by[b] = a;
    }

    for (int day = 1; day < k; day++) {
        for (int i = 0; i < n; i++) {
            if (inf_by[i] == -1) {
                eggs[w][i] = eggs[r][i];
            } else {
                eggs[w][i] = eggs[r][i] ^ eggs[r][inf_by[i]];
            }
        }
        swap(r, w);
    }
 
    for (int i = 0; i < n; i++) {
        cout << to_binary_string(eggs[r][i]) << " \n"[i == n - 1];
    }
}
 
 
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    solve();
    
    return 0;
}
