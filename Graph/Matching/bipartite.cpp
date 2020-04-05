#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int adj[N][N], x[N], y[N], n, m;
bitset <N> used;
bool find_aug(int i){
    if (used[i]) return false;
    used[i] = true;
    for (int j = 1; j <= m; j++)
        if (adj[i][j]){
            if (y[j] == 0){
                x[i] = j; y[j] = i;
                return true;
            }
            if (find_aug(y[j])){
                x[i] = j; y[j] = i;
                return true;
            }
        }
    return false;
}

int matching(){
    int match = 0;
    for (int i = 1; i <= n; i++){
        used.reset(); 
        match += find_aug(i);
    }
    return match;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int e, u, v; cin >> n >> m >> e;
    while (e--){
        cin >> u >> v; 
        adj[u][v] = true;
    }
    cout << matching() << '\n';
}