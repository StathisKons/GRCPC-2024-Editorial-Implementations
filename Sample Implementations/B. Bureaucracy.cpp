#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m;

    pair<int,int> p[n];

    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        p[i]={(a-1)/m, i+1}; // save pair {qi, i}
    }

    sort(p, p+n); // sort by qi breaking ties with i

    for(int i=0; i<n; i++){
        cout << p[i].second << " ";
    }
    
}