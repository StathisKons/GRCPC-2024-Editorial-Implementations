#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int edge[n+1][n+1]; //adjacency matrix 

    priority_queue<pair<int,int>> pq;
    set<int> used;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j){
                cin >> edge[i][0];
                edge[0][i] = edge[i][0]; // save self-loops as edges to node 0 
                continue;
            }
            cin >> edge[i][j];
            
        }
    }

    // Prim’s algorithm starting from the artificial node 0
    int start = 0;
    used.insert(start);
    
    // Push all edges from node 0
    for(int i=0; i<=n; i++){
        if(i!=start);
        pq.push({edge[start][i]*-1,i});
    }
    
    ll ans = 0;
    
    // Prim’s logic
    while(!pq.empty()){
        int cur = pq.top().second;
        
        if(used.find(cur)== used.end()){
            
            ans+=pq.top().first*-1; // add cheapest edge
            pq.pop();

            // push all edges from the newly added node
            for(int i=0; i<=n; i++){
                if(i==cur) continue;
                pq.push({edge[cur][i]*-1,i});
            }

            used.insert(cur);
            continue;
        } 
        pq.pop();
       
    }

    cout << ans << endl;
    
}