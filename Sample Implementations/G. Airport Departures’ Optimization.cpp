#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,T;
    cin >> n >> T;

    vector<pair<int,int>> flights(n+1); // flights[i] = {departure time, reward = b[i] - c[i]}
    
    ll ans = 0; // sum of all c[i] + dp[n]

    for(int i=1; i<=n; i++){
        int t, b, c;
        cin >> t >> b >> c;
        flights[i] = {t,b-c}; // save Departure time and b-c for every flight
        ans+=c; //Add c to answer
    }

    // Precompute p[i] with sweepline technique
    
    vector<ll> p(n+1); // p[i] = index of the last flight that can be scheduled before flight i
    
    int pre = 0;
    for(int i=1; i<=n; i++){
        while(pre<n && flights[pre+1].first+T <= flights[i].first){
            pre++;
        }
        p[i] = pre;
    }

    vector<ll> dp(n+1); // dp[i] = max reward using first i flights

    //Caclculate dp
    for(int i=1; i<=n; i++){
        dp[i] = max(dp[i-1],flights[i].second + dp[p[i]]);
    }

    ans += dp[n];

    cout << ans;
}